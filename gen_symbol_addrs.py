from pathlib import Path

import pynm

elf_p = Path("/home/dragorn421/Documents/oot_cc0redo/zelda_ocarina_mq_dbg.elf")
map_p = Path("/home/dragorn421/Documents/oot_cc0redo/build/z64.map")

symbol_addrs_p = Path("symbol_addrs.txt")

gen_l = list[str]()

SKIP_SYMS = {"vi", "D_80157D90_", "gZBuffer", "D_8015FA9B", "D_8015FC18"}

already_defined_names: set[str] = set()

OPTS = {
    "D_8015FA98": {"size": "0x210"},
}

for name, addr, size_bad_do_not_use in sorted(
    pynm.nm_syms_sized(str(elf_p)),
    key=lambda it: it[1],
):
    if (
        name.startswith("_")
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
    options = dict[str, str]()
    # used to set size using size_bad_do_not_use but actually IDO messes up symbol sizes
    options.update(OPTS.get(name, {}))
    if options:
        l += " // " + " ".join(f"{k}:{v}" for k, v in options.items())
    gen_l.append(l)

gen_txt = "\n".join(gen_l)

text = symbol_addrs_p.read_text()

text1, text2, textTmp = text.partition("// MAGIC_START_AUTO_GEN_SYMBOL_ADDRS\n")
text3, text4, text5 = textTmp.partition("// MAGIC_END_AUTO_GEN_SYMBOL_ADDRS\n")
symbol_addrs_p.write_text("".join((text1, text2, gen_txt, "\n", text4, text5)))
