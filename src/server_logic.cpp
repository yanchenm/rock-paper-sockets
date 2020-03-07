#include <iostream>
#include <thread>
#include <future>
#include "server_logic.h"

void server_loop(Server &s) {
    Server server;
    try {
        std::cout << "Waiting for client to connect...\n";
        s.accept(server);
        std::cout << "Client connected.\n"
    }
    catch (SocketException &e) {
        std::cout << "Error: " << e.what() << "\n";
        server.close();
        return;
    }

    while (true) {
        // Wait until client sends ready signal
        utils::Move client_ready;
        try {
            server.receive_move(client_ready);
            if (client_ready == utils::Move::ready) {
                std::cout << "Client ready.\n";
                break;
            }
        }
        catch (SocketException &e) {
            std::cout << "Error: " << e.what() << "\n";
        }

        std::future<utils::Move> client_future = std::async(client_listener, std::ref(server));
        utils::Move server_move;

        while (true) {
            std::cout << "Make your move (rock, paper, scissors): ";

            std::string input;
            std::cin >> input;

            if (input == "r" || input == "rock") {
                server_move = utils::Move::rock;
                break;
            } else if (input == "p" || input == "paper") {
                server_move = utils::Move::paper;
                break;
            } else if (input == "s" || input == "scissors") {
                server_move = utils::Move::scissors;
                break;
            } else {
                std::cout << "Please enter a valid move.\n";
            }
        }

        // Find winner
        utils::Move client_move = client_future.get();
        if (utils::operator<(server_move, client_move)) {
            std::cout << "You lost!\n";
            try {
                server.send_move(utils::Move::winner);
            }
            catch (SocketException &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else if (server_move == client_move) {
            std::cout << "It's a tie!\n";
            try {
                server.send_move(utils::Move::tie);
            }
            catch (SocketException &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else {
            std::cout << "You won!\n";
            try {
                server.send_move(utils::Move::loser);
            }
            catch (SocketException &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }

        std::cout << "Play again? ";
        std::string input;
        std::cin >> input;

        if (!(input == "yes" || input == "y")) {
            std::cout << "Thanks for playing! Server terminating...\n";
            return;
        }
    }
}

utils::Move client_listener(Server &s) {
    try {
        utils::Move m;
        s.receive_move(m);
        return m;
    }
    catch (SocketException &e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}
