MAINPROG=puzzle
CXX=g++

CPPFLAGS=-g -fsanitize=address -std=c++17 -MMD -pthread -D_GLIBCXX_DEBUG -Wall

TARGET=$(MAINPROG)
CPPS=$(wildcard *.cpp)
MAINCPPS=$(filter-out unittest.cpp test%.cpp, $(CPPS))

LINK=g++ $(CPPFLAGS)

MAINOBJS=$(MAINCPPS:%.cpp=%.o)


%.o: %.cpp
	$(CXX) $(CPPFLAGS) -o $@ -c $*.cpp

all: $(TARGET)

$(TARGET): $(MAINOBJS)
	$(LINK) $(FLAGS) -o $(TARGET) $^

clean:
	rm -rf *.o $(TARGET)