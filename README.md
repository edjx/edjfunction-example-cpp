# edjfunction-example-cpp

EDJX Platform example function for the C++ language

## Build Instructions

Download and install the [EDJX C++ SDK](https://github.com/edjx/edjx-cpp-sdk)
and [WASI C++ SDK](https://github.com/WebAssembly/wasi-sdk) locally:

    make dependencies EDJX_SDK_VERSION=v21.11.1 WASI_SDK_VERSION=12 WASI_SDK_OS=linux

Build the example application:

    make all

Clean:

    make clean
    make clean-dependencies