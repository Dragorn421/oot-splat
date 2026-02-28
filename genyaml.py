from pathlib import Path

import mapfile_parser

import pyspec


ok_map_p = Path(
    "/home/dragorn421/Documents/oot/build/gc-eu-mq-dbg/oot-gc-eu-mq-dbg.map"
)

ok_map = mapfile_parser.MapFile()
ok_map.readMapFile(ok_map_p)
ok_map_segment_by_name = {s.name: s for s in ok_map}

ok_spec_p = Path("/home/dragorn421/Documents/oot/build/gc-eu-mq-dbg/spec")


ok_spec = pyspec.parse_spec_p(ok_spec_p)


SegmentRomStart = None
SegmentStart = None
SegmentTextStart = None
SegmentTextEnd = None
SegmentDataStart = None
SegmentDataEnd = None
SegmentRoDataStart = None
SegmentRoDataEnd = None
SegmentOvlStart = None
SegmentOvlEnd = None
SegmentRomEnd = None
SegmentBssStart = None
SegmentBssEnd = None
SegmentEnd = None

prev_segment_name = None
prev_segment_romalign = 0
prev_SegmentRomEnd = None
prev_SegmentEnd = None

segment_names = set()

for l in ok_map_p.read_text().splitlines():
    toks = l.split()
    if len(toks) != 4:
        continue
    value, sym, _, _ = toks
    try:
        value = int(value, 16)
    except ValueError:
        continue
    if sym.startswith("_"):
        if sym.endswith("SegmentRomStart"):
            SegmentRomStart = value
        elif sym.endswith("SegmentStart"):
            SegmentStart = value
        elif sym.endswith("SegmentTextStart"):
            SegmentTextStart = value
        elif sym.endswith("SegmentTextEnd"):
            SegmentTextEnd = value
        elif sym.endswith("SegmentDataStart"):
            SegmentDataStart = value
        elif sym.endswith("SegmentDataEnd"):
            SegmentDataEnd = value
        elif sym.endswith("SegmentRoDataStart"):
            SegmentRoDataStart = value
        elif sym.endswith("SegmentRoDataEnd"):
            SegmentRoDataEnd = value
        elif sym.endswith("SegmentOvlStart"):
            SegmentOvlStart = value
        elif sym.endswith("SegmentOvlEnd"):
            SegmentOvlEnd = value
        elif sym.endswith("SegmentRomEnd"):
            SegmentRomEnd = value
        elif sym.endswith("SegmentBssStart"):
            SegmentBssStart = value
        elif sym.endswith("SegmentBssEnd"):
            SegmentBssEnd = value
        elif sym.endswith("SegmentEnd"):
            SegmentEnd = value
            assert (
                SegmentRomStart is not None
                and SegmentStart is not None
                and SegmentTextStart is not None
                and SegmentTextEnd is not None
                and SegmentDataStart is not None
                and SegmentDataEnd is not None
                and SegmentRoDataStart is not None
                and SegmentRoDataEnd is not None
                and SegmentOvlStart is not None
                and SegmentOvlEnd is not None
                and SegmentRomEnd is not None
                and SegmentBssStart is not None
                and SegmentBssEnd is not None
                and SegmentEnd is not None
            )

            segment_name = sym.removeprefix("_").removesuffix("SegmentEnd")

            if prev_segment_name is not None:
                assert prev_SegmentRomEnd is not None and prev_SegmentEnd is not None

                if SegmentRomStart != prev_SegmentRomEnd:
                    print(
                        f"  - [0x{prev_SegmentRomEnd:X}, pad, pad_{prev_SegmentRomEnd:X}]"
                    )
                    print()

                if segment_name in {
                    "boot",
                    "code",
                    "buffers",
                } or segment_name.startswith("ovl_"):
                    segment_type = "code"
                else:
                    segment_type = "bin"
                segment_romalign = ok_spec.find_segment_by_name(segment_name).romalign

                print(f"  - name: {segment_name}")
                print(f"    type: {segment_type}")
                print(f"    start: 0x{SegmentRomStart:X}")
                if segment_romalign != 0 or prev_segment_romalign != 0:
                    print(
                        "    ld_align_segment_start: "
                        f"0x{max(segment_romalign, prev_segment_romalign):X}"
                    )
                prev_segment_romalign = segment_romalign
                print(f"    vram: 0x{SegmentStart:08X}")
                if SegmentStart == prev_SegmentEnd:
                    if segment_name == "boot":
                        print(f"    follows_vram: entry")
                    else:
                        print(f"    follows_vram: {prev_segment_name}")
                if segment_type == "code":
                    bss_size = SegmentBssEnd - SegmentBssStart
                    print(f"    bss_size: 0x{bss_size:X}")
                    print(f"    subsegments:")
                    prev_end = None

                    if segment_name in {"boot", "code"}:
                        map_segment = ok_map_segment_by_name[".." + segment_name]
                        map_segment_bss = ok_map_segment_by_name[
                            ".." + segment_name + ".bss"
                        ]
                        for sec in map_segment:
                            subseg_type = sec.sectionType.removeprefix(".")
                            if subseg_type == "text":
                                subseg_type = "asm"
                            if sec.filepath.stem == "rsp.text":
                                subseg_type = "textbin"
                            subseg_name = f"{sec.filepath.stem}_{sec.vrom:X}_{sec.sectionType.removeprefix(".")}"
                            assert subseg_name not in segment_names
                            segment_names.add(subseg_name)
                            print(
                                f"      - [0x{sec.vrom:X}, {subseg_type}, {subseg_name}]"
                            )
                        for sec in map_segment_bss:
                            print(
                                f"      - {{ name: {sec.filepath.stem}_bss, type: bss, vram: 0x{sec.vram:X} }}"
                            )
                    else:
                        for start, end, subseg_type in (
                            (SegmentTextStart, SegmentTextEnd, "asm"),
                            (SegmentDataStart, SegmentDataEnd, "data"),
                            (SegmentRoDataStart, SegmentRoDataEnd, "rodata"),
                            (SegmentOvlStart, SegmentOvlEnd, "bin"),
                            (SegmentBssStart, SegmentBssEnd, "bss"),
                        ):
                            if start != end:
                                if prev_end is not None and prev_end != start:
                                    print(
                                        f"      - [0x{SegmentRomStart + (prev_end - SegmentStart):X}, pad]"
                                    )
                                if subseg_type == "bss":
                                    subseg_name = f"bss_{start:X}"
                                    assert subseg_name not in segment_names
                                    segment_names.add(subseg_name)
                                    print(
                                        f"      - {{ name: {subseg_name}, type: bss, vram: 0x{start:X} }}"
                                    )
                                else:
                                    print(
                                        f"      - [0x{SegmentRomStart + (start - SegmentStart):X}, {subseg_type}]"
                                    )
                                prev_end = end
                print()

            prev_segment_name = segment_name
            prev_SegmentRomEnd = SegmentRomEnd
            prev_SegmentEnd = SegmentEnd

            SegmentRomStart = None
            SegmentStart = None
            SegmentTextStart = None
            SegmentTextEnd = None
            SegmentDataStart = None
            SegmentDataEnd = None
            SegmentRoDataStart = None
            SegmentRoDataEnd = None
            SegmentOvlStart = None
            SegmentOvlEnd = None
            SegmentRomEnd = None
            SegmentBssStart = None
            SegmentBssEnd = None
            SegmentEnd = None
