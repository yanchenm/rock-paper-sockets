#include <stdexcept>
#include "utils.h"

bool operator<(Move &a, Move &b) {
    if (a == Move::ready || b == Move::ready) {
        throw std::invalid_argument("Invalid move received.");
    }

    switch (a) {
        case Move::rock:
            return b == Move::paper;
        case Move::paper:
            return b == Move::scissors;
        case Move::scissors:
            return b == Move::rock;
        default:
            throw std::invalid_argument("Invalid move received.");
    }
}

bool operator>(Move &a, Move &b) {
    if (a == Move::ready || b == Move::ready) {
        throw std::invalid_argument("Invalid move received.");
    }

    switch (a) {
        case Move::rock:
            return b == Move::scissors;
        case Move::paper:
            return b == Move::rock;
        case Move::scissors:
            return b == Move::paper;
        default:
            throw std::invalid_argument("Invalid move received.");
    }
}