BIN=gui
CXXFLAGS=--std=c++0x
OBJS=gui.o

$(BIN): $(OBJS)
	$(CXX) -o $(BIN) $(CXXFLAGS) $(OBJS)

$.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f $(BIN) $(OBJS)
