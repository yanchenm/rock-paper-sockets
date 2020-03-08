#include <stdexcept>
#include "utils.h"

namespace utils {
    bool operator<(Move &a, Move &b) {
        if (a == Move::ready || b == Move::ready) {
            throw std::invalid_argument("Invalid move for comparison");
        }

        if (a == Move::winner || b == Move::winner) {
            throw std::invalid_argument("Invalid move for comparison");
        }

        if (a == Move::loser || b == Move::loser) {
            throw std::invalid_argument("Invalid move for comparison");
        }

        if (a == Move::tie || b == Move::tie) {
            throw std::invalid_argument("Invalid move for comparison");
        }

        switch (a) {
            case Move::rock:
                return b == Move::paper;
            case Move::paper:
                return b == Move::scissors;
            case Move::scissors:
                return b == Move::rock;
            default:
                throw std::invalid_argument("Invalid move for comparison");
        }
    }

    bool operator>(Move &a, Move &b) {
        if (a == Move::ready || b == Move::ready) {
            throw std::invalid_argument("Invalid move for comparison");
        }

        if (a == Move::winner || b == Move::winner) {
            throw std::invalid_argument("Invalid move for comparison");
        }

        if (a == Move::loser || b == Move::loser) {
            throw std::invalid_argument("Invalid move for comparison");
        }

        if (a == Move::tie || b == Move::tie) {
            throw std::invalid_argument("Invalid move for comparison");
        }

        switch (a) {
            case Move::rock:
                return b == Move::scissors;
            case Move::paper:
                return b == Move::rock;
            case Move::scissors:
                return b == Move::paper;
            default:
                throw std::invalid_argument("Invalid move for comparison");
        }
    }
}