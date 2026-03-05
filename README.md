# oot-splat

This repo is used to re-decompile non-cc0 parts of the OoT decomp.

oot-splat https://github.com/Dragorn421/oot-splat

oot_cc0redo https://github.com/Dragorn421/oot/tree/oot_cc0redo

## Contributing

### 1 Clone the repo

Clone and enter the oot-splat repo:

```sh
git clone --recurse-submodules git@github.com:Dragorn421/oot-splat.git
cd oot-splat
```

or

```sh
git clone git@github.com:Dragorn421/oot-splat.git
cd oot-splat
git submodule update --init --recursive
```

### 2 Install requirements

Create a python virtual environment

```sh
python3 -m venv .venv
```

Active the venv

```sh
. .venv/bin/activate
```

Install requirements

```sh
pip install -r requirements.txt
```

### 3 Copy baserom

Copy oot-gc-eu-mq-dbg.z64 to `./baserom.z64`

### 4 Build

Active the venv

```sh
. .venv/bin/activate
```

Run splat

```sh
./splat.sh
```

Set `IDO7RECOMP` to the path to the ido 7.1 recomp `cc` binary, and run `make` (or faster, `make -jN` with N your amount of cpu cores)

If you have the zeldaret/oot decomp set up, you have the ido 7.1 recomp in `path/to/oot/tools/ido_recomp/linux/7.1/cc`.

```sh
export IDO7RECOMP=path/to/ido_recomp/linux/7.1/cc
make
```

## Tools

This repo has

- asm-differ (`./diff.py`)
- decomp-permuter (`./tools/decomp-permuter/{import,permuter}.py`)
- m2c (`./tools/m2c/m2c.py`)
- `./tools/mkctx.py` (given the path to a .c file, creates a ctx.c file for m2c)
- `./sym_info.py` (find symbols info by ram or rom address. Without arguments, prints a list of all symbols)
- `./tools/pw.py` (given a function name, automatically finds the file it's in and calls `./tools/decomp-permuter/import.py`)
