#include <stdexcept>
#include <iostream>
#include "utils.h"

namespace utils {
    bool operator<(const Move &a, const Move &b) {
        if (!utils::is_valid_move(a) || !utils::is_valid_move(b)) {
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


    bool operator>(const Move &a, const Move &b) {
        if (!utils::is_valid_move(a) || !utils::is_valid_move(b)) {
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

    bool is_valid_move(const Move &a) {
        bool isValid = a == Move::rock || a == Move::paper || a == Move::scissors;
        return isValid;
    }

    Move get_move_input() {
        while (true) {
            std::cout << "Make your move (rock [r], paper [p], scissors [s]): ";

            std::string input;
            std::cin >> input;

            if (input == "r" || input == "rock") {
                return Move::rock;
            }

            if (input == "p" || input == "paper") {
                return Move::paper;
            }

            if (input == "s" || input == "scissors") {
                return Move::scissors;
            }

            std::cout << "Please enter a valid move.\n";
        }
    }
}