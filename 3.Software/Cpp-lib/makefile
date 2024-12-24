# 指定编译器
CXX = g++
# 指定编译选项
CXXFLAGS = -I./Inc -Wall -std=c++11 # 添加 -I 选项指定头文件目录

# 可执行文件名
TARGET = main.exe

# 源文件
SRCS = main.cpp ./Src/WzSerialPort.cpp ./Src/mrh5.cpp

# 对应的目标文件
OBJS = $(SRCS:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ -static-libgcc -static-libstdc++

# 生成对象文件
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# 清理目标
clean:
	rm -f $(OBJS) $(TARGET)

# 伪目标
.PHONY: all clean
