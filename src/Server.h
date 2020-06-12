#ifndef ROCK_PAPER_SOCKETS_SERVER_H
#define ROCK_PAPER_SOCKETS_SERVER_H

#include "Socket.h"

class Server : public Socket {
public:
    void bind(int port);
    void listen();
    void accept(Server &s);
};


#endif //ROCK_PAPER_SOCKETS_SERVER_H
