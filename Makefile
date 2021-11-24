# Library versions
#EDJX_SDK_VERSION := v21.11.1
EDJX_SDK_VERSION := v21.11.0-e0f9233
WASI_SDK_VERSION := 12
WASI_SDK_VERSION_FULL := $(WASI_SDK_VERSION).0
# Possible WASI_SDK_OS values: linux, macos, mingw
WASI_SDK_OS := linux

# Paths to SDK libraries
DOWNLOAD_DIR := ./downloaded
DEPENDENCIES_DIR := ./opt

WASI_SDK_PATH := $(DEPENDENCIES_DIR)/wasi-sdk
EDJX_SDK_PATH := $(DEPENDENCIES_DIR)/edjx-cpp-sdk

INCLUDE_DIR := $(EDJX_SDK_PATH)/include
LIB_DIR := $(EDJX_SDK_PATH)/lib

# Directories used by the project
SRC_DIR := src/
BUILD_DIR := build/
TARGET_DIR := bin/

# Name of the compiled WASM executable
TARGET := edjfunction_example_cpp.wasm

# Source cpp files
SRC := $(notdir $(wildcard $(SRC_DIR)/*.cpp))

# Compiler options
CC := $(WASI_SDK_PATH)/bin/clang++
CFLAGS := --target=wasm32-wasi --sysroot=$(WASI_SDK_PATH)/share/wasi-sysroot/ -Wall -Werror -O2 -fno-exceptions -static
CLIBS := -ledjx
CPPFLAGS += -MD -MP

# Additional shell commands
MKDIR_P := mkdir -p

# ---------------------
#  Compilation Targets
# ---------------------

.PHONY: all
all: directories $(TARGET_DIR)/$(TARGET)

.PHONY: directories
directories: $(TARGET_DIR) $(BUILD_DIR)

$(TARGET_DIR):
	$(MKDIR_P) $@

$(BUILD_DIR):
	$(MKDIR_P) $@

$(TARGET_DIR)/$(TARGET): $(SRC:%.cpp=$(BUILD_DIR)/%.o)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -L$(LIB_DIR) -o $@ $^ $(CLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

-include $(SRC:%.cpp=$(BUILD_DIR)/%.d)

.PHONY: clean
clean:
	rm -f $(TARGET_DIR)/$(TARGET) $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d

# ------------------------------------------------------
#  Automatically download the WASI SDK and the EDJX SDK
# ------------------------------------------------------

.PHONY: dependencies
dependencies: $(DOWNLOAD_DIR) $(DEPENDENCIES_DIR) $(EDJX_SDK_PATH) $(WASI_SDK_PATH)

$(DOWNLOAD_DIR):
	$(MKDIR_P) $@

$(DEPENDENCIES_DIR):
	$(MKDIR_P) $@

$(EDJX_SDK_PATH):
	wget https://github.com/edjx/edjx-cpp-sdk/releases/download/${EDJX_SDK_VERSION}/edjx-cpp-sdk-${EDJX_SDK_VERSION}-wasi-${WASI_SDK_VERSION}.tar.gz -P $(DOWNLOAD_DIR)
	tar -xvf $(DOWNLOAD_DIR)/edjx-cpp-sdk-${EDJX_SDK_VERSION}-wasi-${WASI_SDK_VERSION}.tar.gz -C $(DOWNLOAD_DIR)
	mv $(DOWNLOAD_DIR)/edjx-cpp-sdk-${EDJX_SDK_VERSION}-wasi-${WASI_SDK_VERSION} $@

$(WASI_SDK_PATH):
	wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_SDK_VERSION}/wasi-sdk-${WASI_SDK_VERSION_FULL}-$(WASI_SDK_OS).tar.gz -P $(DOWNLOAD_DIR)
	tar -xvf $(DOWNLOAD_DIR)/wasi-sdk-${WASI_SDK_VERSION_FULL}-$(WASI_SDK_OS).tar.gz -C $(DOWNLOAD_DIR)
	mv $(DOWNLOAD_DIR)/wasi-sdk-$(WASI_SDK_VERSION_FULL) $@

.phony: clean-dependencies
clean-dependencies:
	rm -rf $(DOWNLOAD_DIR) $(DEPENDENCIES_DIR)