cmake_minimum_required(VERSION 3.13)

set (This Tests)

include_directories(include)

include_directories(src)

set(Sources ${CMAKE_CURRENT_LIST_DIR}/testRunner.c)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    gmock_main
    ${Headers}
    ${ACTUAL_LIBRARIES}
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

