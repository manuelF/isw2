CXX=g++
BING=gui
BIND=decisions
CXXFLAGS=-std=c++0x -Wall
OBJS=sensors/weather_station.o sensors/weather_report.o sensors/external_conditions.o master_plan.o history.o \
		 actuators/actuators_handler.o actuators/antibiotic_actuator.o \
		 plant_log_item.o action_log_item.o plant.o

all: $(BIND) $(BING)

$(BIND): $(OBJS) $(BIND).o
	$(CXX) -o $(BIND) $(CXXFLAGS) $(OBJS) $(BIND).o

$(BING): $(OBJS) $(BING).o
	$(CXX) -o $(BING) $(CXXFLAGS) $(OBJS) $(BING).o

$.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f $(OBJS) $(BIND) $(BING) $(BIND).o $(BING).o
