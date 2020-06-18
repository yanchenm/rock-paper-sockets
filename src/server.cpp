#include "server.h"

server::server() : socket(), address{.sin_family=AF_INET} {}

void server::bind(int port) {
    if (!is_valid()) {
        throw socket_exception("No socket to bind.");
    }

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);

    if (::bind(socket_fd, (sockaddr *) &address, sizeof(address)) == -1) {
        throw socket_exception("Failed to bind to port " + std::to_string(port));
    }
}

void server::listen() {
    if (!is_valid()) {
        throw socket_exception("No socket to listen on.");
    }

    if (::listen(socket_fd, 1) == -1) {
        throw socket_exception("Failed to listen.");
    }
}

void server::accept(server &s) {
    int addr_size = sizeof(address);
    s.socket_fd = ::accept(socket_fd, (sockaddr *) &address, (socklen_t *) &addr_size);

    if (s.socket_fd == -1) {
        throw socket_exception("Failed to accept connection.");
    }
}