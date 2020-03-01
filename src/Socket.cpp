#include "Socket.h"

Socket::Socket() : socket_fd(-1), address{.sin_family=AF_INET} {};

Socket::~Socket() {
    if (is_valid()) {
        close(socket_fd);
    }
}

void Socket::create() {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (!is_valid()) {
        throw SocketException("Unable to create socket.");
    }
}

void Socket::send_move(Move m) {
    if (!is_valid()) {
        throw SocketException("There is no valid socket to send on.");
    }

    char message;
    switch (m) {
        case Move::rock:
            message = 'r';
            break;
        case Move::paper:
            message = 'p';
            break;
        case Move::scissors:
            message = 's';
            break;
        case Move::ready:
            message = 'x';
            break;
    }

    if (send(socket_fd, &message, 1, 0) == -1) {
        throw SocketException("Move send failed.");
    }
}

void Socket::receive_move(Move &m) {
    if (!is_valid()) {
        throw SocketException("There is no valid socket to receive on.");
    }

    char message[1];
    if (recv(socket_fd, message, 1, 0) == -1) {
        throw SocketException("Move receive failed.");
    }

    switch (message[0]) {
        case 'r':
            m = Move::rock;
            break;
        case 'p':
            m = Move::paper;
            break;
        case 's':
            m = Move::scissors;
            break;
        case 'x':
            m = Move::ready;
            break;
    }
}

bool Socket::is_valid() {
    return socket_fd != -1;
}