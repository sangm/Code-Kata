CXX = g++
CXXFLAGS = -pthread -Wall -std=c++11

TestVector: TestVector.cpp vector.h
	$(CXX) $(CXXFLAGS) $^ -lgtest -lpthread -o $@

.PHONY: clean
clean:
	rm -rf *.o
	
