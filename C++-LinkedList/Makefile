CXX = g++
CXXFLAGS = -g -pthread -Wall -std=c++11

TestSingleLL: TestSingleLL.cpp SingleLL.o
	$(CXX) $(CXXFLAGS)  -lgtest -lpthread $^ -o $@
SingleLL.o: SingleLL.cpp SingleLL.h
	$(CXX) $(CXXFLAGS) -c SingleLL.cpp

