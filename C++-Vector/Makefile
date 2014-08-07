CXX = g++
CXXFLAGS = -pthread -Wall -std=c++11

TestVector: TestVector.cpp vector.cpp vector.h
	$(CXX) $(CXXFLAGS) TestVector.cpp -lgtest -lpthread -o $@

.PHONY: clean
clean:
	rm -rf *.o
	
