#!/usr/bin/python3

import argparse
from pathlib import Path
import subprocess


def preprocess(in_file: Path):
    cpp_command = [
        "gcc",
        "-nostdinc",
        "-E",
        "-P",
        "-Iinclude",
        "-undef",
        "-D__sgi",
        "-D_LANGUAGE_C",
        "-DNON_MATCHING",
        str(in_file),
    ]
    try:
        return subprocess.check_output(cpp_command, encoding="utf-8")
    except subprocess.CalledProcessError:
        print(cpp_command)
        raise


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("file", help="path of c file to be processed")
    args = parser.parse_args()

    preprocessed = preprocess(args.file)

    Path("ctx.c").write_text(preprocessed)


if __name__ == "__main__":
    main()
