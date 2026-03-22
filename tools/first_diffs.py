#!/usr/bin/env python3
from pathlib import Path
import sys

import mapfile_parser
import numpy as np

sys.path.insert(0, str(Path(__file__).parent.parent))
import sym_info


baserom_p = Path("baserom.z64")
built_rom_p = Path("build/rom.z64")

built_map_path = Path("build/rom.map")
built_elf_path = Path("build/rom.elf")

baserom_bytes = np.frombuffer(baserom_p.read_bytes(), dtype=np.byte)
built_rom_p = np.frombuffer(built_rom_p.read_bytes(), dtype=np.byte)

n = min(len(baserom_bytes), len(built_rom_p))

(diffs_inds,) = np.nonzero(baserom_bytes[:n] != built_rom_p[:n])

map_file = mapfile_parser.mapfile.MapFile()
map_file.readMapFile(built_map_path)

local_symbols = sym_info.read_local_symbols_from_mdebug(built_elf_path)
sym_info.merge_local_symbols(map_file, local_symbols)

IGN_IMMEDIATES = True

for off in diffs_inds:
    if off % 4 >= 2 and IGN_IMMEDIATES:
        # ignore potential immediates
        continue
    info, sections = map_file.findSymbolByVrom(off)
    try:
        print(f"0x{off:X}", info.getAsStrPlusOffset() if info is not None else "?")
    except BrokenPipeError:
        break
