#include "Socket.h"

Socket::Socket() : socket_fd(-1), address{.sin_family=AF_INET} {};

Socket::~Socket() {
    close();
}

void Socket::create() {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (!is_valid()) {
        throw SocketException("Unable to create socket.");
    }
}

void Socket::close() {
    if (is_valid()) {
        ::close(socket_fd);
    }
}

void Socket::send_move(utils::Move m) {
    if (!is_valid()) {
        throw SocketException("There is no valid socket to send on.");
    }

    char message;
    switch (m) {
        case utils::Move::rock:
            message = 'r';
            break;
        case utils::Move::paper:
            message = 'p';
            break;
        case utils::Move::scissors:
            message = 's';
            break;
        case utils::Move::ready:
            message = 'x';
            break;
        case utils::Move::winner:
            message = 'w';
            break;
        case utils::Move::loser:
            message = 'l';
            break;
        case utils::Move::tie:
            message = 't';
            break;
    }

    if (send(socket_fd, &message, 1, 0) == -1) {
        throw SocketException("utils::Move send failed.");
    }
}

void Socket::receive_move(utils::Move &m) {
    if (!is_valid()) {
        throw SocketException("There is no valid socket to receive on.");
    }

    char message[1];
    if (recv(socket_fd, message, 1, 0) == -1) {
        throw SocketException("utils::Move receive failed.");
    }

    switch (message[0]) {
        case 'r':
            m = utils::Move::rock;
            break;
        case 'p':
            m = utils::Move::paper;
            break;
        case 's':
            m = utils::Move::scissors;
            break;
        case 'x':
            m = utils::Move::ready;
            break;
        case 'w':
            m = utils::Move::winner;
            break;
        case 'l':
            m = utils::Move::loser;
            break;
        case 't':
            m = utils::Move::tie;
            break;
    }
}

bool Socket::is_valid() {
    return socket_fd != -1;
}