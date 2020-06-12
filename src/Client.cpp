#include "Client.h"

void Client::connect(const std::string &address, int port) {
    if (!is_valid()) {
        throw SocketException("No socket to connect on.");
    }

    sockaddr_in server{.sin_family=AF_INET, .sin_port=htons(port)};

    if (inet_pton(AF_INET, address.c_str(), &server.sin_addr) == -1) {
        throw SocketException("Invalid address.");
    }

    if (::connect(socket_fd, (sockaddr *) &server, sizeof(server)) == -1) {
        throw SocketException("Failed to connect to server.");
    }
}