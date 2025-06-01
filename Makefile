CC := clang-19
CXX := clang++-19
CFLAGS := -std=c99 -Wall -g
CXXFLAGS := -std=c++17 -Wall -g
LDFLAGS := 

OUT_DIR := build
CACHE_DIR := $(OUT_DIR)/.cache
SRC_DIRS := $(shell find src -type d)
CACHE_SUBDIRS := $(patsubst src/%,$(CACHE_DIR)/%,$(SRC_DIRS))

SRC := $(wildcard src/*.c) $(wildcard src/**/*.c)
OBJ := $(patsubst src/%.c,$(CACHE_DIR)/%.o,$(SRC))

DOT_EXE := $(empty)
DOT_LIB := $(empty)
DOT_DLL := $(empty)

ifeq ($(OS), Windows_NT)
	DOT_EXE += .exe
	DOT_LIB += .lib
	DOT_DLL += .dll
else
	UNAME_S += $(shell uname -s)
#	DOT_EXE += .out
	DOT_LIB += .a
	
	ifeq ($(UNAME_S), Linux)
		DOT_DLL += .so
		LDFLAGS += -ldl -lpthread
	endif

	ifeq ($(UNAME_S), Darwin)
		DOT_DLL += .dylib
		LDFLAGS += -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa
	endif
endif

all: $(OUT_DIR) $(CACHE_DIR) $(OUT_DIR)/foo$(DOT_EXE)

.PHONY: all clean

$(OUT_DIR)/foo$(DOT_EXE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(CACHE_DIR)/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OUT_DIR): $(OUT_DIR)
	@mkdir $@

$(CACHE_DIR): $(CACHE_DIR)
	@mkdir $@ 
	@mkdir -p $(CACHE_SUBDIRS)

clean: $(OUT_DIR)
	@rm -rv $(OUT_DIR)