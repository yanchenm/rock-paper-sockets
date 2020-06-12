#include <iostream>
#include "client_logic.h"

void client_loop(Client &c) {
    while (true) {
        try {
            c.send_move(utils::Move::ready);

            utils::Move move, result;
            move = utils::get_move_input();

            c.send_move(move);
            c.receive_move(result);

            switch (result) {
                case utils::Move::winner:
                    std::cout << "You won!\n";
                    break;
                case utils::Move::loser:
                    std::cout << "You lost!\n";
                    break;
                case utils::Move::tie:
                    std::cout << "It's a tie!\n";
                    break;
                default:
                    throw std::runtime_error("Invalid result received.");
            }
        } catch (SocketException &e) {
            std::cout << "Error: " << e.what() << "\n";
        }

        std::cout << "Play again? ";
        std::string input;
        std::cin >> input;

        if (!(input == "yes" || input == "y")) {
            std::cout << "Thanks for playing!\n";
            c.close();
            return;
        }
    }
}