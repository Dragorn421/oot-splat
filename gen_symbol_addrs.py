# SPDX-FileCopyrightText: 2026 Dragorn421
# SPDX-License-Identifier: CC0-1.0

from pathlib import Path

import pynm

elf_p = Path("/home/dragorn421/Documents/oot_cc0redo/build/ntsc-1.2/oot-ntsc-1.2.elf")
map_p = Path("/home/dragorn421/Documents/oot_cc0redo/build/ntsc-1.2/oot-ntsc-1.2.map")

symbol_addrs_p = Path("symbol_addrs.txt")

gen_l = list[str]()

SKIP_SYMS = {
    "forwards",
    "backwards",
    "rspbootTextEnd",
    "cic6105TextEnd",
    "aspMainTextEnd",
    "gspF3DZEX2_NoN_PosLight_fifoTextEnd",
    "gspS2DEX2d_fifoTextEnd",
    "njpgdspMainTextEnd",
    "sSoundFontTableHeader",
    "sSequenceTableHeader",
    "sSampleBankTableHeader",
    "aspMainDataEnd",
    "gspF3DZEX2_NoN_PosLight_fifoDataEnd",
    "gspS2DEX2d_fifoDataEnd",
}

already_defined_names: set[str] = set()

for name, addr, size_bad_do_not_use in sorted(
    pynm.nm_syms_sized(str(elf_p)),
    key=lambda it: it[1],
):
    if (
        (
            name.startswith("_")
            and not (name.startswith("__ull") or name.startswith("__ll"))
        )
        or name.startswith("jtbl_")
        or name.startswith("L8")
        or name in SKIP_SYMS
        or addr < 0x8000_0000
    ):
        continue
    if name in already_defined_names:
        continue
    already_defined_names.add(name)
    l = f"{name} = 0x{addr:08X};"
    gen_l.append(l)

gen_txt = "\n".join(gen_l)

text = symbol_addrs_p.read_text()

text1, text2, textTmp = text.partition("// MAGIC_START_AUTO_GEN_SYMBOL_ADDRS\n")
text3, text4, text5 = textTmp.partition("// MAGIC_END_AUTO_GEN_SYMBOL_ADDRS\n")
symbol_addrs_p.write_text("".join((text1, text2, gen_txt, "\n", text4, text5)))
