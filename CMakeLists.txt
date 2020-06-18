cmake_minimum_required(VERSION 3.1...3.15)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

set (CMAKE_CXX_STANDARD 11)
set (GCC_THREAD_LINK_FLAG "-pthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_THREAD_LINK_FLAG}")
project(rock-paper-sockets)

add_executable(rock-paper-sockets src/main.cpp src/utils.h src/utils.cpp src/socket.cpp src/socket.h src/socket_exception.h src/server.cpp src/server.h src/client.cpp src/client.h src/server_logic.cpp src/server_logic.h src/client_logic.cpp src/client_logic.h)