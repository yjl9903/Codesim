# Codesim

Diff two single C++ code file.

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
    codesim [FLAGS] [OPTIONS] [--] [ARGS]

FLAGS:
    -h, --help            Prints help information
        --skip-compile    Skip compile
    -V, --version         Prints version information
    -v, --verbose         Verbose log

OPTIONS:
        --files <files>...    extra files

ARGS:
    <code1>    source code
    <code2>    target code
```

If you have not installed `clang`, you can pre-compile two codes manually, and pass `--skip-compile` to `codesim`.

```bash
codesim a.out b.out --skip-compile
```

## Github Actions

If you do not have a Mac OS machine, you can try it with the power of [Github Actions](https://github.com/features/actions). Github Actions config file has been provided in `/.github/workflows/`. You can put the example codes in this repo, and run "Detect Code Plagiarism" in the web page manually.

## Docker

Dockerfile is also provided. You can use it to avoid installing deps in your machine.
