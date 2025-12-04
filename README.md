# netutils

## Description

**netutils** is a lightweight cross-platform CLI tool providing helpful network utilities:

- Print raw binary bytes from input
- Generate checksums in **HEX** or **binary** formats
- Validate MAC addresses

Written in **C++17**, using:

- `argparse` for argument parsing
- Internal modular libraries (`checksum`, `macaddr`)
- Portable build system using **CMake**

---

## Usage

```
netutils [OPTIONS]
```

### Mutually Exclusive Options (required — choose one)

| Short Flag | Long Flag    | Description                                   |
| ---------- | ------------ | --------------------------------------------- |
| `-b`       | `--binary`   | Print raw binary bytes of the input           |
| `-c`       | `--checksum` | Calculate checksum for the input              |
| `-vm`      | `--vmac`     | Validate whether input is a valid MAC address |

### Additional Options

| Short Flag | Long Flag   | Description                                                   | Default |
| ---------- | ----------- | ------------------------------------------------------------- | ------- |
| `-f`       | `--format`  | Checksum output format (`hex` or `bin`), only valid with `-c` | `hex`   |
| `-h`       | `--help`    | Show help message                                             | —       |
| `-v`       | `--version` | Show version                                                  | —       |

---

### Examples

Print raw binary bytes:

```
netutils -b "Hello"
```

Generate checksum (HEX):

```
netutils -c "my raw binary data"
```

Generate checksum (binary):

```
netutils -c "my data" -f bin
```

Validate MAC address:

```
netutils -vm "AA:BB:CC:DD:EE:FF"
```

---

## Build Manually

### Requirements

- C++17 compatible compiler:
  - Linux: `g++` or `clang++`
  - Windows: `MSVC`
- `cmake` (>= 3.16 recommended)

### Clone and Build

```
git clone https://github.com/homocodian/netutils.git
cd netutils
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

---

## Install Manually

### Linux (via CMake)

```
sudo cmake --install . --config Release --prefix /usr/local
```

Or copy manually:

```
sudo cp netutils /usr/local/bin/netutils
```

### Windows (via CMake)

```
cmake --install . --config Release --prefix "C:\Program Files\netutils"
```

Or manually copy `netutils.exe` into any directory listed in system `PATH`.

---

## Run After Install

```
netutils --help
```

---

## Prebuilt Downloads (x86_64)

### Linux (x86_64)

```
wget https://github.com/homocodian/netutils/releases/download/v1.0.0/netutils-x86_64-linux
chmod +x netutils-x86_64-linux
sudo mv netutils-x86_64-linux /usr/local/bin/netutils
```

### Windows (x86_64)

Download and run:

```
https://github.com/homocodian/netutils/releases/download/v1.0.0/netutils-x86_64-windows.exe
```

Move the `.exe` anywhere you like, optionally add the directory to `PATH`.

---

## Supported Platforms

| OS      | Architecture |
| ------- | ------------ |
| Linux   | `x86_64`     |
| Windows | `x86_64`     |

---

## Notes

- Compound short flags like `-abc` are **not supported**
- `-f / --format` is only allowed when used with `-c / --checksum`

---

## License (MIT)

```
MIT License

Copyright (c) 2025

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
