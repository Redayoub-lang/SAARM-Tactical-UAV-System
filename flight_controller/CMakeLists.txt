add_library(FlightControllerCore 
    src/ekf_quaternion.cpp 
    src/can_bus_ids.cpp
)
target_include_directories(FlightControllerCore PUBLIC include)