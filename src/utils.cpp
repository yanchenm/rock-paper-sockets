#include <stdexcept>
#include "utils.h"

namespace utils {
    bool operator<(Move &a, Move &b) {
        if (!utils::isValidMove(a) || !utils::isValidMove(b)) {
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
        if (!utils::isValidMove(a) || !utils::isValidMove(b)) {
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

    bool isValidMove(Move &a) {
        bool isValid = a == Move::rock || a == Move::paper || a == Move::scissors;
        return isValid;
    }
}