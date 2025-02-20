#include <iostream>
#include <thread>
#include <future>
#include "server_logic.h"

void server_loop(Server &listener) {
    Server s;
    try {
        std::cout << "Waiting for client to connect...\n";
        listener.accept(s);
        std::cout << "Client connected.\n";
    }
    catch (SocketException &e) {
        std::cout << "Error: " << e.what() << "\n";
        s.close();
        return;
    }

    while (true) {
        // Wait until client sends ready signal
        utils::Move client_ready;
        try {
            std::cout << "Receiving move\n";
            s.receive_move(client_ready);
            if (client_ready != utils::Move::ready) {
                continue;
            } else {
                std::cout << "Client ready.\n";
            }
        }
        catch (SocketException &e) {
            std::cout << "Error: " << e.what() << "\n";
            s.close();
            return;
        }

        std::future<utils::Move> client_future = std::async(client_listener, std::ref(s));
        utils::Move server_move;

        server_move = utils::get_move_input();

        // Find winner
        utils::Move client_move = client_future.get();
        if (utils::operator<(server_move, client_move)) {
            std::cout << "You lost!\n";
            try {
                s.send_move(utils::Move::winner);
            }
            catch (SocketException &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else if (server_move == client_move) {
            std::cout << "It's a tie!\n";
            try {
                s.send_move(utils::Move::tie);
            }
            catch (SocketException &e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        } else {
            std::cout << "You won!\n";
            try {
                s.send_move(utils::Move::loser);
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
            s.close();
            return;
        }
    }
}

utils::Move client_listener(Server &s) {
    while (true) {
        try {
            utils::Move m;
            s.receive_move(m);
            return m;
        }
        catch (SocketException &e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}
