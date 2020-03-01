#ifndef ROCK_PAPER_SOCKETS_UTILS_H
#define ROCK_PAPER_SOCKETS_UTILS_H

enum class Move {
    rock, paper, scissors, ready
};

bool operator<(const Move &a, const Move &b);

bool operator>(const Move &a, const Move &b);

#endif //ROCK_PAPER_SOCKETS_UTILS_H
