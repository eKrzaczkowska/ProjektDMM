cmake_minimum_required(VERSION 3.13)


add_library(Library 
    ${CMAKE_CURRENT_LIST_DIR}/adc.c
    ${CMAKE_CURRENT_LIST_DIR}/displayDriver.c
    ${CMAKE_CURRENT_SOURCE_DIR}/voltage.c
) 

set(ACTUAL_LIBRARIES Library)

