# Codesim

Diff two single C++ code file.

## Installation

Ensure you have installed `clang` in your computer, and corresponding `nm`, `objdump` has been properly set in your path env.

Run the following in your terminal

```bash
curl -fsSL https://bina.egoist.sh/yjl9903/Codesim | sh
```

Or you can manually install codesim. Get the latest Rust.

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Install codesim with cargo.

```bash
cargo install codesim
```

Install codesim locally.

```bash
cargo install --path .
```

**Mac OS / Linux is highly recommended**.

## Usage

```bash
$ codesim --help
codesim 0.1.0
Diff two single C++ code file

USAGE:
    codesim [FLAGS] [OPTIONS] [--] [ARGS]

FLAGS:
    -h, --help            Prints help information
        --norm            Normalize final score
        --skip-compile    Skip compile
    -V, --version         Prints version information
    -v, --verbose         Verbose log

OPTIONS:
        --csv <csv>           Output CSV
        --files <files>...    extra files

ARGS:
    <code1>    source code
    <code2>    target code
```

For example, run codesim on the example codes.

```bash
codesim examples/aplusb.cpp examples/cplusd.cpp
codesim examples/cplusd.cpp examples/aplusb.cpp
```

If you have not installed `clang`, you can compile two codes manually, and pass `--skip-compile` to `codesim`.

```bash
codesim a.out b.out --skip-compile
```

You can also run codesim on multiple files pairwise.

```bash
codesim --files examples/Sum/sample1.c examples/Sum/sample2.c examples/Sum/sample3.c
```

## Docker

Dockerfile is provided. You can use it to avoid installing deps in your machine.
