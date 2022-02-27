PROGRAM=MonteCarloApproximation
CXX=g++
CXXFLAGS=-std=c++11 -g -Wall -fopenmp
OBJS=$(PROGRAM).o ArgParser.o

$(PROGRAM):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(PROGRAM)

$(PROGRAM).o: $(PROGRAM).cpp $(PROGRAM).hpp

ArgParser.o: ArgParser.cpp ArgParser.hpp

clean:
	rm -rf $(OBJS) core $(PROGRAM) *.log
