#!/usr/bin/env python3

# SPDX-FileCopyrightText: 2026 Dragorn421
# SPDX-License-Identifier: CC0-1.0

import argparse
import csv
import dataclasses


@dataclasses.dataclass(frozen=True)
class Sym:
    vram_start: int
    name: str
    type: str
    segment: str
    subsegment: str
    subsegment_type: str
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
                int(row["vram_start"], 16),
                row["name"],
                row["type"],
                row["segment"],
                row["subsegment"],
                row["subsegment_type"],
                tuple(referenced_by),
            )
        )

sym_by_name = {_sym.name: _sym for _sym in syms}

parser = argparse.ArgumentParser()
parser.add_argument("segment")
parser.add_argument(
    "--section",
    nargs="+",
    help=(
        "only show this section besides text,"
        " eg --section rodata will only show text and rodata"
    ),
)
args = parser.parse_args()

section_by_subsegment_type = {
    "asm": "text",
    "c": "text",
    "textbin": "text",
    "hasm": "text",
    "data": "data",
    "rodata": "rodata",
    ".rodata": "rodata",
    "bss": "bss",
}

syms_by_section: dict[str, list[Sym]] = {}
for sym in syms:
    if sym.segment != args.segment:
        continue
    section = section_by_subsegment_type.get(sym.subsegment_type)
    assert section is not None, sym
    syms_by_section.setdefault(section, []).append(sym)

text_subsegments = sorted({_sym.subsegment for _sym in syms_by_section["text"]})
color_by_subsegment: dict[str, str] = {}
for subsegment in text_subsegments:
    h = (len(color_by_subsegment) * 0.7) % 1
    color_by_subsegment[subsegment] = f"{h} 1 1"

if args.section:
    for section in list(syms_by_section.keys()):
        if section != "text" and section not in args.section:
            del syms_by_section[section]

section_by_sym_name = {
    _sym.name: _section for _section, _syms in syms_by_section.items() for _sym in _syms
}

vram_start_by_section: dict[str, int] = {}
for section, section_syms in syms_by_section.items():
    vram_start_by_section[section] = min(_s.vram_start for _s in section_syms)


colw = 10
x_by_section = {
    "text": 0 * colw,
    "data": 1 * colw,
    "rodata": 2 * colw,
    "bss": 3 * colw,
}


def gprint(l: str):
    print(l)


gprint("digraph {")

for section, section_syms in syms_by_section.items():
    section_vram_start = vram_start_by_section[section]
    x = x_by_section[section]
    filtered_syms: list[Sym] = []
    for sym in sorted(section_syms, key=lambda sym: sym.vram_start):
        if sym.type in {"label", "jtbl_label"}:
            continue
        filtered_syms.append(sym)
    cur_subsegment = None
    i = 0
    for sym in filtered_syms:
        if 0:
            # y = vram position
            y = -(sym.vram_start - section_vram_start) / 500
        y = -i / len(filtered_syms) * 100
        i += 1
        if cur_subsegment != sym.subsegment:
            if cur_subsegment is not None:
                gprint("}")
            cur_subsegment = sym.subsegment
            gprint(f"subgraph cluster_{cur_subsegment}_{section} " "{")
        assert cur_subsegment is not None
        color = None
        if section == "text":
            color = color_by_subsegment[cur_subsegment]
        elif section == "rodata":
            if sym.type == "jtbl":
                color = "magenta"
        gprint(
            f'"{sym.name}"'
            " ["
            f' pos = "{x},{y}!"'
            + (f' color="{color}"' if color is not None else "")
            + " ]"
        )
    if cur_subsegment is not None:
        gprint("}")

for section, section_syms in syms_by_section.items():
    for sym in section_syms:
        for sym_ref_by in sym.referenced_by:
            if (
                # ignore references from outside the segment
                sym_ref_by in section_by_sym_name
                # ignore same-section references
                and section_by_sym_name[sym_ref_by] != section
                # only show references from text
                and section_by_sym_name[sym_ref_by] == "text"
            ):
                gprint(
                    f'"{sym_ref_by}" -> "{sym.name}"'
                    f' [ color = "{color_by_subsegment[sym_by_name[sym_ref_by].subsegment]}" ]'
                )

gprint("}")
