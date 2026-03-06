#!/usr/bin/env python3
# m2c wrapper


from pathlib import Path
import subprocess
import sys


C_IDENTIFIER_ALLOWED = frozenset(
    "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "_" "0123456789"
)


def bad_usage():
    print(f"Usage: {sys.argv[0]} FUNC [m2c.py args...]")
    exit(1)


if len(sys.argv) <= 1:
    bad_usage()

func_name = sys.argv[1]

if not all(_c in C_IDENTIFIER_ALLOWED for _c in func_name):
    bad_usage()

s_files = dict[Path, list[str]]()

for dir_p, dirnames, filenames in Path("src").walk():
    for filename in filenames:
        file_p = dir_p / filename
        matching_lines = [
            _l
            for _l in file_p.read_text().splitlines()
            if "GLOBAL_ASM" in _l and func_name in _l
        ]
        if matching_lines:
            s_files[file_p] = [
                _l.split("GLOBAL_ASM")[1].strip('"()') for _l in matching_lines
            ]

s_file = None
err = None
if len(s_files) == 1:
    (c_file,) = s_files.keys()
    (s_files_list,) = s_files.values()
    if len(s_files_list) == 1:
        s_file = s_files_list[0]
    else:
        err = "Found several matching GLOBAL_ASM"

if s_file is None:
    if err is None:
        if s_files:
            print("Found several files")
            print(s_files)
        else:
            print("Found no file")
    else:
        print(err)
        print(s_files)
    exit(1)

subprocess.check_call(
    [
        "tools/mkctx.py",
        str(c_file),
    ]
)

subprocess.check_call(
    [
        "tools/m2c/m2c.py",
        "--context",
        "ctx.c",
        s_file,
        *sys.argv[2:],
    ]
)
