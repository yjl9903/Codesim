# Codesim

## Installation

Get the latest Rust.

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Get the latest llvm and libclang at [Release LLVM 13.0.0 · llvm/llvm-project](https://github.com/llvm/llvm-project/releases/tag/llvmorg-13.0.0).

Make sure that you have downloaded `libclany.dylib` (for Mac OS) or `libclang.so` (for Linux) in right place (for example `/usr/lib` or `/usr/local/lib`). You can see more details at [clang-sys](https://github.com/KyleMayes/clang-sys#linking).

Install codesim locally.

```bash
cargo install --path .
```

## Usage

```bash
$ codesim --help
codesim 0.1.0
Diff two single C++ code

USAGE:
    codesim [FLAGS] <code1> <code2>

FLAGS:
    -h, --help       Prints help information
    -V, --version    Prints version information
    -v, --verbose    verbose

ARGS:
    <code1>    source code
    <code2>    target code
```
