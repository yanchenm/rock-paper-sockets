#ifndef ROCK_PAPER_SOCKETS_SERVER_H
#define ROCK_PAPER_SOCKETS_SERVER_H

#include "socket.h"

class Server : public SocketInterface {
private:
    sockaddr_in address;
public:
    Server();

    void bind(int port);
    void listen();
    void accept(SocketInterface &s);
};


#endif //ROCK_PAPER_SOCKETS_SERVER_H
