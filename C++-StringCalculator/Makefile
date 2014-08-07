CXX = g++
CXXFLAGS = -g -Wall -Wextra -pthread

all: TestStringCalculator 
TestStringCalculator: StringCalculator.o TestStringCalculator.o main.cpp
	$(CXX) $(CXXFLAGS) $^ -lgtest -lpthread -o $@
	
TestStringCalculator.o: TestStringCalculator.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@
StringCalculator.o: StringCalculator.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

.PHONY: clean
clean:
	rm -rf *.o
