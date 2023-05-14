cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_STANDARD 11)

project(sample)

#enable_testing()

#add_subdirectory(googletest)

add_subdirectory(test)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

include_directories(src)

include_directories(include)

set(Headers  
${CMAKE_CURRENT_LIST_DIR}/include/adc.h
${CMAKE_CURRENT_LIST_DIR}/include/displayDriver.h
${CMAKE_CURRENT_LIST_DIR}/include/voltage.h
)

add_subdirectory(src)

