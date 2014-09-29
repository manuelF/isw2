cmake_minimum_required(VERSION 2.8.4)
project(plantApp)

add_subdirectory (actuators)
add_subdirectory (arduino)
add_subdirectory (sensors)

#include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES action_log_item.cpp basic_datatypes.h client.cpp decision.cpp decisions_maker.cpp
 external_conditions_log_item.cpp gui.cpp history.cpp level.cpp master_plan.cpp messages.cpp plant.cpp
 plant_log_item.cpp server.cpp system.cpp timer.cpp)

add_executable(plantApp ${SOURCE_FILES})