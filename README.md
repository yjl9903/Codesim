# Codesim

## Installation

Get the latest Rust.

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Install codesim locally.

```bash
cargo install --path .
```

Ensure you have installed `clang` in your computer, and corresponding `nm`, `objdump` has been properly set in your path env.

**Mac OS is highly recommended**.

## Usage

```bash
$ codesim --help
codesim 0.1.0
Diff two single C++ code file

USAGE:
    codesim [FLAGS] <code1> <code2>

FLAGS:
    -h, --help            Prints help information
        --skip-compile    Skip compile
    -V, --version         Prints version information
    -v, --verbose         Verbose log

ARGS:
    <code1>    source code
    <code2>    target code
```

If you have not installed `clang`, you can pre-compile two codes manually, and pass `--skip-compile` to `codesim`.

```bash
codesim a.out b.out --skip-compile
```
