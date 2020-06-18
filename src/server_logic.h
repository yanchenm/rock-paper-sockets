#ifndef ROCK_PAPER_SOCKETS_SERVER_LOGIC_H
#define ROCK_PAPER_SOCKETS_SERVER_LOGIC_H

#include "server.h"
#include "utils.h"

void server_loop(server &listener);
utils::Move client_listener(server &s);

#endif //ROCK_PAPER_SOCKETS_SERVER_LOGIC_H
