# Directories
PDIR = $(shell pwd)
SRC_DIR = $(PDIR)/src
BUILD_DIR = $(PDIR)/build

BUILD_BITOP = $(BUILD_DIR)/bitop
BUILD_DISK_UTILS = $(BUILD_DIR)/disk_utils

BIN_DIR = $(PDIR)/bin

# Sources and Objects
BITOP_SRC = $(wildcard $(SRC_DIR)/bitop/*.c)
BITOP_OBJ = $(patsubst $(SRC_DIR)/bitop/%.c, $(BUILD_BITOP)/%.o, $(BITOP_SRC))

DISK_UTILS_SRC = $(wildcard $(SRC_DIR)/disk_utils/*.c)
DISK_UTILS_OBJ = $(patsubst $(SRC_DIR)/disk_utils/%.c, $(BUILD_DISK_UTILS)/%.o, $(DISK_UTILS_SRC))

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -I$(PDIR)/include -lm -g

#temperorly disabled Werror
#CFLAGS = -Wall -Wextra -Werror -I$(PDIR)/include

# Targets
# all: prepare_dirs $(BIN_DIR)/test_bitop $(BIN_DIR)/test_disk_utils
all: prepare_dirs $(BIN_DIR)/test_bitop $(BIN_DIR)/test_disk_utils $(BIN_DIR)/fadd $(BIN_DIR)/mkvd $(BIN_DIR)/diskinfo $(BIN_DIR)/vdls $(BIN_DIR)/fget $(BIN_DIR)/faddall


#create directories, if not exist.
prepare_dirs:
	mkdir -p $(BUILD_BITOP)
	mkdir -p $(BUILD_DISK_UTILS)
	mkdir -p $(BIN_DIR)

$(BUILD_BITOP)/%.o: $(SRC_DIR)/bitop/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DISK_UTILS)/%.o: $(SRC_DIR)/disk_utils/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/test_bitop: $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/test_bitop.c
	$(CC) $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/test_bitop.c -o $@ $(CFLAGS)

$(BIN_DIR)/test_disk_utils: $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/test_disk_utils.c
	$(CC) $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/test_disk_utils.c -o $@ $(CFLAGS)

### new added.
$(BIN_DIR)/fadd: $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/add.c
	$(CC) $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/add.c -o $@ $(CFLAGS)

$(BIN_DIR)/mkvd: $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/mkvd.c
	$(CC) $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/mkvd.c -o $@ $(CFLAGS)

$(BIN_DIR)/diskinfo: $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/diskinfo.c
	$(CC) $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/diskinfo.c -o $@ $(CFLAGS)

$(BIN_DIR)/vdls: $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/vdls.c
	$(CC) $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/vdls.c -o $@ $(CFLAGS)

$(BIN_DIR)/fget: $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/get.c
	$(CC) $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/get.c -o $@ $(CFLAGS)

$(BIN_DIR)/faddall: $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/addall.c
	$(CC) $(BITOP_OBJ) $(DISK_UTILS_OBJ) $(PDIR)/src/addall.c -o $@ $(CFLAGS)


###
run_test_bitop:
	cd $(BIN_DIR) && ./test_bitop

run_test_disk_utils:
	cd $(BIN_DIR) && ./test_disk_utils

clean:
	rm -fv $(BUILD_BITOP)/*.o $(BUILD_DISK_UTILS)/*.o 
	rm -fv $(BIN_DIR)/fadd $(BIN_DIR)/mkvd $(BIN_DIR)/diskinfo  $(BIN_DIR)/test_disk_utils $(BIN_DIR)/test_bitop $(BIN_DIR)/vdls
	rm -fv $(BIN_DIR)/fget $(BIN_DIR)/faddall
	rm -fv $(BIN_DIR)/disk.vd

