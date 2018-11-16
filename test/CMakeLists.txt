cmake_minimum_required(VERSION 3.7.0)
project(test_moneycpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/catch)

if(BOOST_MULTIPRECISION OR BOOST_OPTIONAL)
   include_directories(${BOOST_INCLUDE_DIR})
endif()

if(BOOST_MULTIPRECISION)
   add_definitions(-DHAS_BOOST_MULTIPRECISION)
endif()

if(BOOST_OPTIONAL)
   link_directories(${BOOST_LIB_DIR})
   add_definitions(-DHAS_BOOST_OPTIONAL)
endif()

if(COUNTRY_AND_CURRENCY_DB)
   add_definitions(-DHAS_COUNTRY_AND_CURRENCY_DB)
endif()

file(GLOB headers ${CMAKE_SOURCE_DIR}/include/*.h ${CMAKE_SOURCE_DIR}/include/ext/*.h)
file(GLOB SOURCES "*.cpp") #"include/*.cpp"

add_executable(test_moneycpp ${SOURCES} ${headers})

if(BUILD_TESTS)
    enable_testing()

    add_test(NAME "test_moneycpp" COMMAND "test_moneycpp" "-r compact")
    set_tests_properties("test_moneycpp"
        PROPERTIES
        PASS_REGULAR_EXPRESSION "Passed all.*")
    set_tests_properties("test_moneycpp"
        PROPERTIES
        FAIL_REGULAR_EXPRESSION "Failed \\d+ test cases")
    set_tests_properties("test_moneycpp"
        PROPERTIES
        TIMEOUT 120)
endif()