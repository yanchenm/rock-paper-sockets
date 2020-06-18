#ifndef ROCK_PAPER_SOCKETS_CLIENT_H
#define ROCK_PAPER_SOCKETS_CLIENT_H

#include <arpa/inet.h>
#include "socket.h"

class client : public socket {
public:
    void connect(const std::string &address, int port);
};


#endif //ROCK_PAPER_SOCKETS_CLIENT_H
