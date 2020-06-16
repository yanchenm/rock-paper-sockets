cmake_minimum_required(VERSION 3.1...3.15)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

set (CMAKE_CXX_STANDARD 11)
project(rock-paper-sockets)

add_executable(rock-paper-sockets src/main.cpp src/utils.h src/utils.cpp src/Socket.cpp src/Socket.h src/SocketException.h src/Server.cpp src/Server.h src/Client.cpp src/Client.h src/server_logic.cpp src/server_logic.h src/client_logic.cpp src/client_logic.h)