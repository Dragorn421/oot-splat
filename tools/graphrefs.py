#!/usr/bin/env python3
import argparse
import csv
import dataclasses
from pathlib import Path


@dataclasses.dataclass(frozen=True)
class Sym:
    name: str
    type: str
    subsegment: str
    referenced_by: tuple[str, ...]


syms = list[Sym]()

with open(".splat/splat_symbols.csv") as f:
    for row in csv.DictReader(f):
        if row["referenced_by"] == "":
            referenced_by = []
        else:
            referenced_by = row["referenced_by"].split("|")
        syms.append(
            Sym(
                row["name"],
                row["type"],
                row["subsegment"],
                tuple(referenced_by),
            )
        )

syms_by_name = {_s.name: _s for _s in syms}

# s_referencee in referencees_map[s] means s references s_referencee
referencees_map = {_s: set[Sym]() for _s in syms}
for s in syms:
    for rs in s.referenced_by:
        referencees_map[syms_by_name[rs]].add(s)

parser = argparse.ArgumentParser()
parser.add_argument("subsegment")
parser.add_argument("--no-outside", action="store_true")
parser.add_argument("--only-functions", action="store_true")
parser.add_argument("--highlight-decompiled", help=".c file to look in")
parser.add_argument("--group-similar-refs", action="store_true")
parser.add_argument("--show-external-files", action="store_true")
args = parser.parse_args()

not_decompiled: list[str] = []
highlight_decompiled = False
if args.highlight_decompiled is not None:
    highlight_decompiled = True
    c = Path(args.highlight_decompiled).read_text()
    for l in c.splitlines():
        l = l.strip()
        if "#pragma GLOBAL_ASM" in l:
            func_name = l.split("/")[-1].split(".")[0]
            not_decompiled.append(func_name)


subsegment_syms = [_s for _s in syms if _s.subsegment == args.subsegment]
subsegment_syms_set = set(subsegment_syms)


def gprint(l: str):
    print(l)


gprint("digraph {")

all_nodes = dict[str, Sym]()

for s in subsegment_syms:
    if s.type == "label":
        continue
    if args.only_functions and s.type != "func":
        continue
    all_nodes[s.name] = s
    is_referenced_by_outside_only = True
    if args.group_similar_refs:
        referenced_by = {syms_by_name[_rs] for _rs in s.referenced_by}
        referencers_that_only_reference_this: list[Sym] = []
        for rs in s.referenced_by:
            if syms_by_name[rs].subsegment != args.subsegment:
                if args.no_outside:
                    continue
            else:
                is_referenced_by_outside_only = False
            if len(referencees_map[syms_by_name[rs]] & subsegment_syms_set) == 1:
                assert referencees_map[syms_by_name[rs]] & subsegment_syms_set == {s}
                referencers_that_only_reference_this.append(syms_by_name[rs])
            else:
                suff = ""
                if args.show_external_files:
                    suff = " in " + syms_by_name[rs].subsegment
                all_nodes[f"{rs}{suff}"] = syms_by_name[rs]
                gprint(f' "{rs}{suff}" -> {s.name}')
        if referencers_that_only_reference_this:
            group_node_name = ", ".join(
                _s.name for _s in referencers_that_only_reference_this[:3]
            )
            if len(referencers_that_only_reference_this) > 3:
                group_node_name += (
                    f", ... ({len(referencers_that_only_reference_this)})"
                )
            gprint(f' "{group_node_name}" -> {s.name}')
            gprint(f' "{group_node_name}" [color = red]')
    else:
        for rs in s.referenced_by:
            if syms_by_name[rs].subsegment != args.subsegment:
                if args.no_outside:
                    continue
            else:
                is_referenced_by_outside_only = False
            suff = ""
            if args.show_external_files:
                suff = " in " + syms_by_name[rs].subsegment
            all_nodes[f"{rs}{suff}"] = syms_by_name[rs]
            gprint(f' "{rs}{suff}" -> {s.name}')
    if is_referenced_by_outside_only:
        gprint(f" {s.name} [color = green]")
    if highlight_decompiled and s.name not in not_decompiled:
        gprint(f" {s.name} [fillcolor = magenta style = filled]")

for n, s in all_nodes.items():
    if s.subsegment != args.subsegment:
        gprint(f' "{n}" [color = red]')

gprint("}")
