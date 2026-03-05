#!/usr/bin/env python3
# permuter wrapper

from pathlib import Path
import subprocess
import sys


C_IDENTIFIER_ALLOWED = frozenset(
    "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "_" "0123456789"
)


def bad_usage():
    print(f"Usage: {sys.argv[0]} FUNC [permuter import.py args...]")
    exit(1)


if len(sys.argv) <= 1:
    bad_usage()

func_name = sys.argv[1]

if not all(_c in C_IDENTIFIER_ALLOWED for _c in func_name):
    bad_usage()

c_files = list[Path]()

for dir_p, dirnames, filenames in Path("src").walk():
    for filename in filenames:
        file_p = dir_p / filename
        if any(
            "GLOBAL_ASM" in _l and func_name in _l
            for _l in file_p.read_text().splitlines()
        ):
            c_files.append(file_p)

if len(c_files) == 1:
    c_file = c_files[0]
else:
    if c_files:
        print("Found several files")
        print(c_files)
    else:
        print("Found no file")
    exit(1)

subprocess.call(
    [
        "tools/decomp-permuter/import.py",
        str(c_file),
        func_name,
        *sys.argv[2:],
    ]
)
