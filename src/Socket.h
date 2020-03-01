#ifndef ROCK_PAPER_SOCKETS_SOCKET_H
#define ROCK_PAPER_SOCKETS_SOCKET_H

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "SocketException.h"
#include "utils.h"

class Socket {
    int socket_fd;
    sockaddr_in address;

public:
    Socket();
    virtual ~Socket();

    void create();
    void send_move(Move m);
    void receive_move(Move &m);
    bool is_valid();
};


#endif //ROCK_PAPER_SOCKETS_SOCKET_H
