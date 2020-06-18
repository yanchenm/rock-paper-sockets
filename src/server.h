#ifndef ROCK_PAPER_SOCKETS_SERVER_H
#define ROCK_PAPER_SOCKETS_SERVER_H

#include "socket.h"

class server : public socket {
protected:
    sockaddr_in address;
public:
    server();

    void bind(int port);
    void listen();
    void accept(server &s);
};


#endif //ROCK_PAPER_SOCKETS_SERVER_H
