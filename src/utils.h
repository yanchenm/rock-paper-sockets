#ifndef ROCK_PAPER_SOCKETS_UTILS_H
#define ROCK_PAPER_SOCKETS_UTILS_H

namespace utils {
    enum class Move {
        rock, paper, scissors, ready, winner, tie, loser
    };

    bool operator<(const Move &a, const Move &b);
    bool isValidMove(const Move &move);
    bool operator>(const Move &a, const Move &b);
}

#endif //ROCK_PAPER_SOCKETS_UTILS_H
