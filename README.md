# Codesim

## Installation

Get the latest Rust.

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Install codesim.

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
