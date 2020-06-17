#include "Server.h"

Server::Server() : Socket(), address{.sin_family=AF_INET} {}

void Server::bind(int port) {
    if (!is_valid()) {
        throw SocketException("No socket to bind.");
    }

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);

    if (::bind(socket_fd, (sockaddr *) &address, sizeof(address)) == -1) {
        throw SocketException("Failed to bind to port " + std::to_string(port));
    }
}

void Server::listen() {
    if (!is_valid()) {
        throw SocketException("No socket to listen on.");
    }

    if (::listen(socket_fd, 1) == -1) {
        throw SocketException("Failed to listen.");
    }
}

void Server::accept(Server &s) {
    int addr_size = sizeof(address);
    s.socket_fd = ::accept(socket_fd, (sockaddr *) &address, (socklen_t *) &addr_size);

    if (s.socket_fd == -1) {
        throw SocketException("Failed to accept connection.");
    }
}