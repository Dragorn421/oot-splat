import argparse
from pathlib import Path, PurePosixPath

import mapfile_parser

parser = argparse.ArgumentParser()
parser.add_argument("c_file")
args = parser.parse_args()

map = mapfile_parser.MapFile()
map.readMapFile(Path("build/rom.map"))

c_p = Path(args.c_file)
c = c_p.read_text()
global_asm_lines = [_l for _l in c.splitlines() if "GLOBAL_ASM" in _l]
todo_lines = [["function name", "size (bytes)"]]
for gal in global_asm_lines:
    s_p = PurePosixPath(gal.split('"')[1])
    func_name = s_p.stem
    fsi = map.findSymbolByName(func_name)
    if fsi is None:
        print("Can't find", func_name, "in map")
        continue
    func_size = fsi.symbol.size
    todo_lines.append([func_name, f"{func_size}"])

Path("todo.txt").write_text("\n".join("\t".join(_tl) for _tl in todo_lines))
print("wrote to todo.txt")
