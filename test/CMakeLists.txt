cmake_minimum_required(VERSION 3.7.0)
project(test_moneycpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/catch)

if(BOOST_MULTIPRECISION)
   include_directories(${BOOST_INCLUDE_DIR})
   add_definitions(-DUSE_BOOST_MULTIPRECISION)
endif()

file(GLOB headers ${CMAKE_SOURCE_DIR}/include/*.h)
file(GLOB SOURCES "*.cpp" "include/*.cpp")

add_executable(test_moneycpp ${SOURCES} ${headers})