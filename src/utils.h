#ifndef ROCK_PAPER_SOCKETS_UTILS_H
#define ROCK_PAPER_SOCKETS_UTILS_H

namespace utils {
    enum class Move {
        rock, paper, scissors, ready, winner, tie, loser
    };

    bool operator<(const Move &a, const Move &b);
    bool is_valid_move(const Move &move);
    bool operator>(const Move &a, const Move &b);
    Move get_move_input();
}

#endif //ROCK_PAPER_SOCKETS_UTILS_H
