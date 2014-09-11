BING=gui
BIND=decisions
CXXFLAGS=--std=c++0x -Wall
OBJS=

all: $(BIND) $(BING)

$(BIND): decisions.o $(OBJS)
	$(CXX) -o $(BIND) $(CXXFLAGS) $(OBJS) decisions.o

$(BING): gui.o $(OBJS)
	$(CXX) -o $(BING) $(CXXFLAGS) $(OBJS) gui.o

$.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f decisions.o gui,o $(BIND) $(BING) $(OBJS)
