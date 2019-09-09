# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

CLEANUP = rm -f
MKDIR = mkdir -p
TARGET_EXTENSION=.out
C_COMPILER=gcc

UNITY_ROOT=.

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/unity/general/unity.c \
  $(UNITY_ROOT)/unity/extra/unity_fixture.c \
  src/LedDriver.c \
  test/mock/RuntimeErrorStub.c \
  test/LedDriverTest.c \
  test/test_runners/LedDriverTest_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=\
  -Isrc -Iinclude/util \
  -Itest/mock \
  -I$(UNITY_ROOT)/unity/general \
  -I$(UNITY_ROOT)/unity/extra

SYMBOLS=

all: clean default

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	- ./$(TARGET1) -v

clean:
	$(CLEANUP) $(TARGET1)

ci: CFLAGS += -Werror
ci: default
