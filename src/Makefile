BING=client
BIND=system
BINTEST=tests
CXXFLAGS=-std=c++0x -Wall -pthread -pedantic -g -ggdb

SRCS:=$(wildcard *.cpp) $(wildcard sensors/*.cpp) $(wildcard actuators/*.cpp) $(wildcard arduino/*.cpp)
OBJS:=$(SRCS:%.cpp=%.o)

BINOBJS := $(filter-out $(BIND).o $(BING).o $(BINTEST).o, $(OBJS))


all: $(BIND) $(BING) $(BINTEST)

$.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIND): $(OBJS) $(BIND).o
	$(CXX) -o $(BIND) $(CXXFLAGS) $(BINOBJS) $(BIND).o

$(BING): $(OBJS) $(BING).o
	$(CXX) -o $(BING) $(CXXFLAGS) $(BINOBJS) $(BING).o

$(BINTEST): $(OBJS) $(BINTEST).o
	$(CXX) -o $(BINTEST) $(CXXFLAGS) $(BINOBJS) $(BINTEST).o

clean:
	rm -f $(OBJS) $(BIND) $(BING) $(BIND).o $(BING).o $(BINTEST).o
