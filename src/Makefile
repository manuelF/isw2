BING=gui
BIND=system
CXXFLAGS=-std=c++0x -Wall -pthread -pedantic

SRCS:=$(wildcard *.cpp) $(wildcard sensors/*.cpp) $(wildcard actuators/*.cpp)
OBJS:=$(SRCS:%.cpp=%.o)

BINOBJS := $(filter-out $(BIND).o $(BING).o,$(OBJS))


all: $(BIND) $(BING)

$.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIND): $(OBJS) $(BIND).o
	$(CXX) -o $(BIND) $(CXXFLAGS) $(BINOBJS) $(BIND).o

$(BING): $(OBJS) $(BING).o
	$(CXX) -o $(BING) $(CXXFLAGS) $(BINOBJS) $(BING).o

clean:
	rm -f $(OBJS) $(BIND) $(BING) $(BIND).o $(BING).o
