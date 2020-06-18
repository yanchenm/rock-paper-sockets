#ifndef ROCK_PAPER_SOCKETS_SOCKET_EXCEPTION_H
#define ROCK_PAPER_SOCKETS_SOCKET_EXCEPTION_H


#include <exception>
#include <string>
#include <utility>

class SocketException : public std::exception {
    std::string error_message;

public:
    explicit SocketException(std::string message) : error_message(std::move(message)) {}

    const char *what() {
        return error_message.c_str();
    }
};

#endif //ROCK_PAPER_SOCKETS_SOCKET_EXCEPTION_H
