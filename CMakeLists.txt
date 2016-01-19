cmake_minimum_required(VERSION 2.8.9)

project(econ-simulator)

set(EXECUTABLE_NAME "econ-simulator")

SET(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

file(GLOB SOURCES "src/*.cpp")

include_directories( 
    deps/SFML/include/ 
    include
)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

set(CMAKE_MODULE_PATH "/usr/local/Cellar/sfml/2.3_1/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

find_package(SFML 2 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
