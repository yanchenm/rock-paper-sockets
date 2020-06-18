#ifndef ROCK_PAPER_SOCKETS_SERVER_LOGIC_H
#define ROCK_PAPER_SOCKETS_SERVER_LOGIC_H

#include "server.h"
#include "utils.h"

void server_loop(Server &listener);
utils::Move client_listener(Server &s);

#endif //ROCK_PAPER_SOCKETS_SERVER_LOGIC_H
