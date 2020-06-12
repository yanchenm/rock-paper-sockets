#ifndef ROCK_PAPER_SOCKETS_SOCKETEXCEPTION_H
#define ROCK_PAPER_SOCKETS_SOCKETEXCEPTION_H


#include <exception>
#include <string>

class SocketException : public std::exception {
    std::string error_message;

public:
    explicit SocketException(std::string message) : error_message(message) {}

    const char *what() {
        return error_message.c_str();
    }
};

#endif //ROCK_PAPER_SOCKETS_SOCKETEXCEPTION_H
