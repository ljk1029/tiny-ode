# 默认使用C++编译器
CXX := g++
CXXFLAGS := -Wall -Wextra -g
SRC_DIR := .IO
BUILD_DIR := ../build

# 宏定义，用于选择编程语言
# 默认情况下使用C++，可以通过在命令行中设置 C_MODE=1 来切换到C语言编译
ifeq ($(C_MODE), 1)
    CC := gcc
    CFLAGS := -Wall -Wextra -g
    SRC_EXT := c
else
    CC := $(CXX)
    CFLAGS := $(CXXFLAGS)
    SRC_EXT := cpp
endif

# 获取所有的源文件和对应的目标文件
SRC_FILES := $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.$(SRC_EXT), $(BUILD_DIR)/%.o, $(SRC_FILES))
EXECUTABLE := $(BUILD_DIR)/my_program

# 默认目标：构建可执行文件
all: $(EXECUTABLE)

# 编译规则：将每个源文件编译为对应的目标文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) $(CFLAGS) -c $< -o $@

# 构建可执行文件
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# 清理目标文件和可执行文件
clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)

# 定义伪目标，避免与文件名冲突
.PHONY: all clean
