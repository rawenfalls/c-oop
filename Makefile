# Makefile для компиляции main.cpp с классами AutoFile.h и AutoFile.cpp

# Переменные компилятора и опции компиляции
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Исходные файлы
SRCS = main.cpp AutoFile.cpp
OBJS = $(SRCS:.cpp=.o)

# Имя исполняемого файла
EXEC = my_program

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Правило для компиляции .cpp файлов в .o файлы
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)