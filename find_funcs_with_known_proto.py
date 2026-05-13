#!/usr/bin/env python3

# SPDX-FileCopyrightText: 2026 Dragorn421
# SPDX-License-Identifier: CC0-1.0

import argparse
from pathlib import Path

import mapfile_parser

parser = argparse.ArgumentParser()
parser.add_argument("file", type=Path)
args = parser.parse_args()

map_p = Path("build/thelegendofzelda.map")
map = mapfile_parser.MapFile()
map.readMapFile(map_p)

ctx_p = Path("ctx.c")
c_p = args.file

ctx = ctx_p.read_text()
c = c_p.read_text()

ctx = "".join(
    _l for _l in ctx.splitlines(keepends=True) if "#pragma GLOBAL_ASM" not in _l
)

for l in c.splitlines():
    l = l.strip()
    if "#pragma GLOBAL_ASM" in l:
        func_name = l.split("/")[-1].split(".")[0]
        if func_name in ctx:
            print(func_name, map.findSymbolByName(func_name).symbol.size)
