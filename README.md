```
python3 -m venv .venv
. .venv/bin/activate
pip install -r requirements.txt
ln -s .../oot/baseroms/ntsc-1.2/baserom-decompressed.z64 ./oot-ntsc-1.2-decompressed.z64
cargo build --release --manifest-path asm-processor/rust/Cargo.toml
```
