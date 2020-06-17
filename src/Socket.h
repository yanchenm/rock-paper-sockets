#ifndef ROCK_PAPER_SOCKETS_SOCKET_H
#define ROCK_PAPER_SOCKETS_SOCKET_H

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "SocketException.h"
#include "utils.h"

class Socket {
protected:
    int socket_fd;
public:
    Socket();
    virtual ~Socket();

    void create();
    void close();
    void send_move(utils::Move m);
    void receive_move(utils::Move &m);
    bool is_valid();
};


#endif //ROCK_PAPER_SOCKETS_SOCKET_H
