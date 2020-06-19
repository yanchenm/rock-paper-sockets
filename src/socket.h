#ifndef ROCK_PAPER_SOCKETS_SOCKET_H
#define ROCK_PAPER_SOCKETS_SOCKET_H

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "socket_exception.h"
#include "utils.h"

class SocketInterface {
protected:
    int socket_fd;
public:
    SocketInterface();
    virtual ~SocketInterface();

    void create();
    void assign(int new_socket);
    void close();
    void send_move(utils::Move m) const;
    void receive_move(utils::Move &m) const;
    bool is_valid() const;
};


#endif //ROCK_PAPER_SOCKETS_SOCKET_H
