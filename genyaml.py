import io
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


do_not_decomp = {
    # boot
    "boot/idle",
    "boot/viconfig",
    "boot/z_std_dma",
    "boot/yaz0",
    "boot/z_locale",
    "boot/assert",
    "assert_text_pad_to_isdebug",
    "boot/is_debug",
    "boot/driverominit",
    "boot/mio0",
    "libu64/stackcheck",
    "libu64/debug",
    "libc64/sprintf",
    "libultra/io/piacs",
    "libultra/os/sendmesg",
    "libultra/os/stopthread",
    "libultra/io/viextendvstart",
    "libultra/os/recvmesg",
    "libultra/os/initialize",
    "libultra/libc/ll",
    "libultra/os/exceptasm",
    "libultra/os/thread",
    "libultra/os/destroythread",
    "libultra/libc/bzero",
    "libultra/os/parameters",
    "libultra/os/createthread",
    "libultra/os/setsr",
    "libultra/os/getsr",
    "libultra/os/writebackdcache",
    "libultra/io/vigetnextframebuf",
    "libultra/io/pimgr",
    "kdebugserver",
    "libultra/io/devmgr",
    "libultra/io/pirawdma",
    "libultra/os/virtualtophysical",
    "libultra/io/viblack",
    "libultra/io/sirawread",
    "libultra/os/getthreadid",
    "libultra/os/setintmask",
    "libultra/io/visetmode",
    "libultra/os/probetlb",
    "libultra/os/getmemsize",
    "libultra/os/seteventmesg",
    "libultra/libc/xprintf",
    "libultra/os/unmaptlball",
    "libultra/io/epidma",
    "libultra/libc/string",
    "libultra/os/invalicache",
    "libultra/os/createmesgqueue",
    "libultra/os/invaldcache",
    "libultra/io/si",
    "libultra/os/jammesg",
    "libultra/os/setthreadpri",
    "libultra/os/getthreadpri",
    "libultra/io/epirawread",
    "libultra/io/viswapbuf",
    "libultra/io/epirawdma",
    "libultra/libc/bcmp",
    "libultra/os/gettime",
    "libultra/os/timerintr",
    "libultra/os/getcount",
    "libultra/os/setglobalintmask",
    "libultra/os/setcompare",
    "libultra/libc/bcopy",
    "libultra/os/resetglobalintmask",
    "libultra/os/interrupt",
    "libultra/io/vi",
    "libultra/io/viswapcontext",
    "libultra/io/pigetcmdq",
    "libultra/io/epiread",
    "libultra/io/visetspecial",
    "libultra/io/cartrominit",
    "libultra/os/setfpccsr",
    "libultra/os/getfpccsr",
    "libultra/io/epiwrite",
    "libultra/os/maptlbrdb",
    "libultra/os/yieldthread",
    "libultra/os/getcause",
    "libultra/io/epirawwrite",
    "libultra/libc/xlitob",
    "libultra/libc/ldiv",
    "libultra/libc/xldtob",
    "libultra/io/sirawwrite",
    "sirawwrite_text_pad_to_vimgr",
    "libultra/io/vimgr",
    "libultra/io/vigetcurrcontext",
    "libultra/os/startthread",
    "libultra/io/visetyscale",
    "libultra/io/visetxscale",
    "libultra/os/sethwintrroutine",
    "libultra/os/gethwintrroutine",
    "libultra/os/setwatchlo",
    "data/rsp_boot.text",
    "data/cic6105.text",
    "boot/carthandle",
    "libultra/io/vimodepallan1",
    "libultra/io/vimodentsclan1",
    "libultra/io/vimodempallan1",
    "libultra/io/vimodefpallan1",
    "boot/boot_main",
    "boot/build",
    # code
    "code/z_en_a_keep",
    "code/z_en_item00",
    "code/z_eff_blure",
    "code/z_eff_shield_particle",
    "code/z_eff_spark",
    "code/z_eff_ss_dead",
    "code/z_effect",
    "code/z_effect_soft_sprite",
    "code/z_effect_soft_sprite_old_init",
    "code/flg_set",
    "code/z_DLF",
    "code/z_actor",
    "code/z_actor_dlftbls",
    "code/z_bgcheck",
    "code/z_bg_collect",
    "code/z_bg_item",
    "code/z_camera",
    "code/z_collision_btltbls",
    "code/z_collision_check",
    "code/z_common_data",
    "code/z_debug",
    "code/z_debug_display",
    "code/z_demo",
    "code/z_memory_utils",
    "code/z_draw",
    "code/z_sfx_source",
    "code/z_elf_message",
    "code/z_face_reaction",
    "code/z_env_flags",
    "code/z_fcurve_data",
    "code/z_fcurve_data_skelanime",
    "code/z_horse",
    "code/z_jpeg",
    "code/z_kaleido_setup",
    "code/z_kanfont",
    "code/z_kankyo",
    "code/z_lib",
    "code/z_lifemeter",
    "code/z_lights",
    "code/z_malloc",
    "code/z_map_mark",
    "code/z_moji",
    "code/z_prenmi_buff",
    "code/z_nulltask",
    "code/z_olib",
    "code/z_onepointdemo",
    "code/z_map_exp",
    "code/z_parameter",
    "code/z_path",
    "code/z_frame_advance",
    "code/z_player_lib",
    "code/z_prenmi",
    "code/z_quake",
    "code/z_rcp",
    "code/z_room",
    "code/z_sample",
    "code/z_inventory",
    "code/z_scene",
    "code/z_scene_table",
    "code/z_skelanime",
    "code/z_skin",
    "code/z_skin_awb",
    "code/z_skin_matrix",
    "code/z_sram",
    "code/z_ss_sram",
    "code/z_rumble",
    "code/z_view",
    "code/z_vimode",
    "code/z_viscvg",
    "code/z_vismono",
    "code/z_viszbuf",
    "code/z_vr_box",
    "code/z_vr_box_draw",
    "code/z_player_call",
    "code/z_fbdemo",
    "code/z_fbdemo_triforce",
    "code/z_fbdemo_wipe1",
    "code/z_fbdemo_circle",
    "code/z_fbdemo_fade",
    "code/shrink_window",
    "code/db_camera",
    "code/z_cutscene_spline",
    "code/mempak",
    "code/z_kaleido_manager",
    "code/z_kaleido_scope_call",
    "code/z_play",
    "code/PreRender",
    "code/TwoHeadGfxArena",
    "code/TwoHeadArena",
    "code/audio_stop_all_sfx",
    "audio_stop_all_sfx_text_pad_to_audio_thread_manager",
    "code/audio_thread_manager",
    "code/title_setup",
    "code/game",
    "code/gamealloc",
    "code/graph",
    "code/gfxalloc",
    "code/listalloc",
    "code/main",
    "code/padmgr",
    "code/sched",
    "code/speed_meter",
    "code/sys_cfb",
    "code/sys_math",
    "code/sys_math3d",
    "code/sys_math3d_draw",
    "code/sys_math_atan",
    "code/sys_matrix",
    "code/sys_ucode",
    "code/sys_rumble",
    "code/sys_freeze",
    "code/sys_debug_controller",
    "code/irqmgr",
    "code/debug_malloc",
    "debug_malloc_text_pad_to_fault_gc",
    "code/fault_gc",
    "code/fault_gc_drawer",
    "code/kanread",
    "code/ucode_disas",
    "ucode_disas_text_pad_to_synthesis",
    "audio/internal/synthesis",
    "audio/internal/heap",
    "audio/internal/load",
    "audio/internal/thread",
    "audio/internal/os",
    "audio/internal/playback",
    "audio/internal/effects",
    "audio/internal/seqplayer",
    "audio/game/general",
    "audio/game/sfx",
    "audio/game/sequence",
    "libu64/gfxprint",
    "libu64/rcp_utils",
    "libu64/loadfragment2_gc",
    "libu64/mtxuty-cvt",
    "libu64/relocation_gc",
    "libu64/load_gc",
    "libu64/runtime",
    "libu64/pad",
    "libu64/padsetup",
    "libc64/math64",
    "libc64/fp",
    "libc64/malloc",
    "libc64/qrand",
    "libc64/__osMalloc_gc",
    "libc64/aprintf",
    "libc64/sleep",
    "code/jpegutils",
    "code/jpegdecoder",
    "libultra/io/pfsfreeblocks",
    "libultra/mgu/scale",
    "libultra/gu/sinf",
    "libultra/gu/sins",
    "libultra/io/sptask",
    "libultra/io/motor",
    "libultra/io/siacs",
    "libultra/io/controller",
    "libultra/io/contreaddata",
    "libultra/gu/perspective",
    "libultra/io/sprawdma",
    "libultra/io/sirawdma",
    "libultra/io/sptaskyield",
    "libultra/io/pfsreadwritefile",
    "libultra/io/pfsgetstatus",
    "libultra/mgu/mtxidentf",
    "libultra/gu/lookat",
    "libultra/io/pfsallocatefile",
    "libultra/os/stoptimer",
    "libultra/io/contpfs",
    "libultra/mgu/mtxl2f",
    "libultra/io/pfsfindfile",
    "libultra/gu/sqrtf",
    "libultra/os/afterprenmi",
    "libultra/io/contquery",
    "libultra/gu/lookathil",
    "libultra/io/sp",
    "libultra/mgu/mtxident",
    "libultra/gu/position",
    "libultra/io/sptaskyielded",
    "libultra/gu/rotate",
    "libultra/io/aisetfreq",
    "libultra/os/getactivequeue",
    "getactivequeue_text_pad_to_normalize",
    "libultra/mgu/normalize",
    "libultra/io/dpgetstat",
    "libultra/io/dpsetstat",
    "libultra/io/pfsdeletefile",
    "libultra/gu/ortho",
    "libultra/gu/cosf",
    "libultra/gu/coss",
    "libultra/io/visetevent",
    "libultra/io/pfsisplug",
    "libultra/gu/us2dex",
    "libultra/io/pfsselectbank",
    "libultra/io/contsetch",
    "libultra/io/pfsfilestate",
    "libultra/io/pfsinitpak",
    "libultra/io/pfschecker",
    "libultra/io/aigetlen",
    "aigetlen_text_pad_to_translate",
    "libultra/mgu/translate",
    "libultra/io/contramwrite",
    "libultra/io/contramread",
    "libultra/io/crc",
    "libultra/os/settimer",
    "libultra/io/spgetstat",
    "libultra/io/spsetstat",
    "libultra/os/writebackdcacheall",
    "libultra/os/getcurrfaultedthread",
    "getcurrfaultedthread_text_pad_to_mtxf2l",
    "libultra/mgu/mtxf2l",
    "libultra/libc/llcvt",
    "libultra/io/vigetcurrframebuf",
    "libultra/io/spsetpc",
    "libc/sqrt",
    "libc/fabsf",
    "libc/fmodf",
    "libc/memset",
    "libc/memmove",
    "code/z_message_z_game_over",
    "code/z_construct",
    "data/rsp.text",
    "code/z_effect_soft_sprite_dlftbls",
    "code/z_game_dlftbls",
    "code/z_map_data",
    "code/object_table",
    "data/z_text.data",
    "data/unk_8012ABC0.data",
    "audio/internal/data",
    "audio/game/sfx_params",
    "audio/game/data",
    "audio/game/session_config",
    "audio/game/session_init",
    "libu64/logseverity_gc",
    "libultra/gu/libm_vals",
    "audio/tables/soundfont_table",
    "assets/audio/sequence_font_table",
    "audio/tables/sequence_table",
    "audio/tables/samplebank_table",
    "data/rsp.rodata",
}


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

genyaml_out = io.StringIO()


def yamlprint(*args, **kwargs):
    print(*args, **kwargs, file=genyaml_out)


used_subseg_names = set()

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
                    yamlprint(
                        f"  - [0x{prev_SegmentRomEnd:X}, pad, pad_{prev_SegmentRomEnd:X}]"
                    )
                    yamlprint()

                if segment_name in {
                    "boot",
                    "code",
                    "buffers",
                } or segment_name.startswith("ovl_"):
                    segment_type = "code"
                else:
                    segment_type = "bin"
                segment_romalign = ok_spec.find_segment_by_name(segment_name).romalign

                yamlprint(f"  - name: {segment_name}")
                yamlprint(f"    type: {segment_type}")
                yamlprint(f"    start: 0x{SegmentRomStart:X}")
                if segment_romalign != 0 or prev_segment_romalign != 0:
                    yamlprint(
                        "    ld_align_segment_start: "
                        f"0x{max(segment_romalign, prev_segment_romalign):X}"
                    )
                prev_segment_romalign = segment_romalign
                yamlprint(f"    vram: 0x{SegmentStart:08X}")
                if SegmentStart == prev_SegmentEnd:
                    if segment_name == "boot":
                        yamlprint(f"    follows_vram: entry")
                    else:
                        yamlprint(f"    follows_vram: {prev_segment_name}")
                if segment_type == "code":
                    bss_size = SegmentBssEnd - SegmentBssStart
                    yamlprint(f"    bss_size: 0x{bss_size:X}")
                    yamlprint(f"    subsegments:")
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
                            if sec.filepath.is_relative_to(
                                "build/gc-eu-mq-dbg/data"
                            ) or sec.filepath.is_relative_to(
                                "build/gc-eu-mq-dbg/assets"
                            ):
                                subseg_name = str(
                                    sec.filepath.with_suffix("").relative_to(
                                        "build/gc-eu-mq-dbg"
                                    )
                                )
                            else:
                                subseg_name = str(
                                    sec.filepath.with_suffix("").relative_to(
                                        "build/gc-eu-mq-dbg/src"
                                    )
                                )

                            # work around mapfile_parser bug?
                            if sec.vrom == 0x2C70:
                                assert subseg_name == "boot/assert", subseg_name
                                # 0x10 bytes of padding due to unknown-reason 0x20 alignment of isdebug.c
                                subseg_name = "assert_text_pad_to_isdebug"
                            if sec.vrom == 0x54F0:
                                assert subseg_name == "libultra/io/pimgr", subseg_name
                                subseg_name = "kdebugserver"
                            if sec.vrom == 0x9890:
                                assert (
                                    subseg_name == "libultra/io/sirawwrite"
                                ), subseg_name
                                # another 0x10 of padding
                                subseg_name = "sirawwrite_text_pad_to_vimgr"
                            if sec.vrom == 0xB3AE10:
                                assert (
                                    subseg_name == "code/audio_stop_all_sfx"
                                ), subseg_name
                                # another 0x10 of padding
                                subseg_name = "audio_stop_all_sfx_text_pad_to_audio_thread_manager"
                            if sec.vrom == 0xB4B0B0:
                                assert subseg_name == "code/debug_malloc", subseg_name
                                # another 0x10 of padding
                                subseg_name = "debug_malloc_text_pad_to_fault_gc"
                            if sec.vrom == 0xB51E50:
                                assert subseg_name == "code/ucode_disas", subseg_name
                                # pad_text
                                subseg_name = "ucode_disas_text_pad_to_synthesis"
                            if sec.vrom == 0xB7B2F0:
                                assert (
                                    subseg_name == "libultra/os/getactivequeue"
                                ), subseg_name
                                # another 0x10 of padding
                                subseg_name = "getactivequeue_text_pad_to_normalize"
                            if sec.vrom == 0xB7CDB0:
                                assert (
                                    subseg_name == "libultra/io/aigetlen"
                                ), subseg_name
                                # another 0x10 of padding
                                subseg_name = "aigetlen_text_pad_to_translate"
                            if sec.vrom == 0xB7D670:
                                assert (
                                    subseg_name == "libultra/os/getcurrfaultedthread"
                                ), subseg_name
                                # another 0x10 of padding
                                subseg_name = "getcurrfaultedthread_text_pad_to_mtxf2l"

                            if subseg_name not in do_not_decomp:
                                if subseg_type == "asm":
                                    subseg_type = "c"
                                else:
                                    subseg_type = "." + subseg_type

                            if (subseg_type, subseg_name) in used_subseg_names:
                                assert False, subseg_name
                            used_subseg_names.add((subseg_type, subseg_name))

                            yamlprint(
                                f"      - [0x{sec.vrom:X}, {subseg_type}, {subseg_name}]"
                            )
                        for sec in map_segment_bss:
                            yamlprint(
                                f"      - {{ name: {sec.filepath.stem}_bss, type: bss, vram: 0x{sec.vram:X} }}"
                            )
                    else:
                        for start, end, subseg_type in (
                            (SegmentTextStart, SegmentTextEnd, "asm"),
                            (SegmentDataStart, SegmentDataEnd, "data"),
                            (SegmentRoDataStart, SegmentRoDataEnd, "rodata"),
                            (SegmentOvlStart, SegmentOvlEnd, "rodatabin"),
                            (SegmentBssStart, SegmentBssEnd, "bss"),
                        ):
                            if start != end:
                                if prev_end is not None and prev_end != start:
                                    yamlprint(
                                        f"      - [0x{SegmentRomStart + (prev_end - SegmentStart):X}, pad]"
                                    )
                                if subseg_type == "bss":
                                    subseg_name = f"bss_{start:X}"
                                    yamlprint(
                                        f"      - {{ name: {subseg_name}, type: bss, vram: 0x{start:X} }}"
                                    )
                                else:
                                    yamlprint(
                                        f"      - [0x{SegmentRomStart + (start - SegmentStart):X}, {subseg_type}]"
                                    )
                                prev_end = end
                yamlprint()

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

splatyaml = Path("thelegendofzelda.yaml").read_text()
splatyaml_prefix = splatyaml.split("# MAGIC_START_AUTO_GENYAML")[0]
splatyaml_suffix = splatyaml.split("# MAGIC_END_AUTO_GENYAML\n")[1]
Path("thelegendofzelda.yaml").write_text(
    splatyaml_prefix
    + "# MAGIC_START_AUTO_GENYAML\n\n"
    + genyaml_out.getvalue()
    + "# MAGIC_END_AUTO_GENYAML\n"
    + splatyaml_suffix
)
