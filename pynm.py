#!/usr/bin/env python3
# SPDX-FileCopyrightText: 2024 Dragorn421
# SPDX-License-Identifier: CC0-1.0

import subprocess


def nm_syms(elf: str):
    p = subprocess.Popen(
        [
            "mips-linux-gnu-nm",
            elf,
            "--no-sort",
            "--radix=x",
            "--format=bsd",
        ],
        stdout=subprocess.PIPE,
        encoding="UTF-8",
    )
    for l in p.stdout:
        if l.strip().split()[0] == "U":
            # undefined symbol
            continue
        addr_str, _, name = l.split()
        addr = int(addr_str, 16) & 0xFFFF_FFFF
        yield name, addr


def nm_syms_dict(elf: str):
    return {name: addr for name, addr in nm_syms(elf)}


def nm_syms_sized(elf: str):
    p = subprocess.Popen(
        [
            "mips-linux-gnu-nm",
            elf,
            "--no-sort",
            "--radix=x",
            "--format=sysv",
        ],
        stdout=subprocess.PIPE,
        encoding="UTF-8",
    )
    for l in p.stdout:
        if l.strip() in {
            "",
            f"Symbols from {elf}:",
            "Name                  Value   Class        Type         Size     Line  Section",
        }:
            continue
        toks = l.split("|")
        try:
            if toks[2].strip() == "U":
                # undefined symbol
                continue
            name = toks[0].strip()
            addr_str = toks[1].strip()
            size_str = toks[4].strip()
            addr = int(addr_str, 16) & 0xFFFF_FFFF
            if size_str == "":
                size = None
            else:
                size = int(size_str, 16)
            yield name, addr, size
        except:
            print(f"{l=}")
            print(f"{toks=}")
            raise


def nm_syms_sized_dict(elf: str):
    return {name: (addr, size) for name, addr, size in nm_syms_sized(elf)}


def main():
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument("elf")
    args = parser.parse_args()

    for name, addr in nm_syms(args.elf):
        print(f"{name} = 0x{addr:08X}")


if __name__ == "__main__":
    main()
