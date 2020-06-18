#include "socket.h"

socket::socket() : socket_fd(-1) {};

socket::~socket() {
    close();
}

void socket::create() {
    socket_fd = ::socket(AF_INET, SOCK_STREAM, 0);

    if (!is_valid()) {
        throw socket_exception("Unable to create socket.");
    }
}

void socket::close() {
    if (is_valid()) {
        ::close(socket_fd);
    }
}

void socket::send_move(utils::Move m) const {
    if (!is_valid()) {
        throw socket_exception("There is no valid socket to send on.");
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
        throw socket_exception("Move send failed.");
    }
}

void socket::receive_move(utils::Move &m) const {
    if (!is_valid()) {
        throw socket_exception("There is no valid socket to receive on.");
    }

    char message[1];
    int ret = recv(socket_fd, message, 1, 0);
    if (ret == -1) {
        throw socket_exception("Move receive failed.");
    } else if (ret == 0) {
        throw socket_exception("Connection was terminated.");
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

bool socket::is_valid() const {
    return socket_fd != -1;
}