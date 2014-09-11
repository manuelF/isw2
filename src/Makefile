BING=gui
BIND=decisions
CXXFLAGS=--std=c++0x -Wall -pedantic
OBJS=weather_station.o weather_report.o external_conditions.o master_plan.o history.o \
		 actuators_handler.o antibiotic_actuator.o

all: $(BIND) $(BING)

$(BIND): $(OBJS) decisions.o
	$(CXX) -o $(BIND) $(CXXFLAGS) $(OBJS) decisions.o

$(BING): $(OBJS) gui.o
	$(CXX) -o $(BING) $(CXXFLAGS) $(OBJS) gui.o

$.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f *.o $(BIND) $(BING)
