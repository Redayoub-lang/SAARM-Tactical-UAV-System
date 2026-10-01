set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(TacticalC2Station 
    src/main.cpp 
    src/TacticalC2Server.cpp
)

target_include_directories(TacticalC2Station PRIVATE include)

target_link_libraries(TacticalC2Station PRIVATE 
    Qt5::Core 
    Qt5::Network 
    Qt5::Gui 
    Qt5::Qml 
    Qt5::Quick
)
