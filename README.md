# edjfunction-example-cpp

EDJX Platform example function for the C++ language

## Directory Structure

The directory structure of this repository is as follows:

- `bin/` &mdash; Compiled WASM executable of the example application
(generated during the compilation)
- `build/` &mdash; Intermediate object files of the example application
(generated during the compilation)
- `include/edjx/` &mdash; C++ edjLibrary SDK (headers)
- `lib/edjx/` &mdash; C++ edjLibrary SDK (static library)
- `src/` &mdash; Source code of the example application

## Install WASI C++ SDK

WASI SDK ([github.com/WebAssembly/wasi-sdk](https://github.com/WebAssembly/wasi-sdk))
provides the necessary C and C++ standard library functions. Install the
WASI SDK to `/opt/wasi-sdk/` (so that the path to the bundled compiler is
`/opt/wasi-sdk/bin/clang++`). Use the same WASI SDK version that was used
to build the `libedjx.a` library.

It is possible to install the WASI SDK to
a different location and then manually update the `WASI_SDK_PATH` variable in
the Makefile. It is also possible to specify a different compiler than
the one provided by the WASI SDK by editing the `CC` variable in the Makefile.
However, to avoid any compatibility issues, we recommend using the clang
compiler that comes bundled with the WASI SDK.

## Compile the Example Application

The C++ edjLibrary SDK is already located in `include/edjx/` and
`lib/edjx/`. To compile the example application, run

    make all

The resulting WASM file will be created in `bin/edjfunction_example_cpp.wasm`.

To remove files created during the compilation, run

    make clean

## Note on WASI Imports

EdjExecutor doesn't provide an implementation of functions that the
WASI standard library imports. System functions like `fd_open`, `fd_read`,
`fd_write`, `fd_seek`, `fd_close`, `proc_exit`, `environ_get`,
`environ_sizes_get`, and possibly others, are not implemented and won't work.
The file `/share/wasi-sysroot/lib/wasm32-wasi/libc.imports` in the WASI SDK
installation directory has a list of symbols that are imported by the wasi-libc.