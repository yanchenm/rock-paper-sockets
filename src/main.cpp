#include <iostream>
#include "Server.h"
#include "Client.h"

using namespace std;

void server_loop(Server &s) {

}

void client_loop(Client &c) {

}

int main() {
    cout << "Options:\n";
    cout << "[1] Host a new game.\n";
    cout << "[2] Join an existing game.\n";
    cout << "\nSelect an option: ";

    int option;
    cin >> option;

    if (option == 1) {
        Server listener;
        while (true) {
            cout << "Enter port to listen on: ";

            int port;
            cin >> port;

            cout << "Attempting to start host...\n";
            try {
                listener.create();
                listener.bind(port);
                listener.listen();

                cout << "Server listening on port " << port << "\n";
                break;
            } catch (SocketException &e) {
                cout << "Error: " << e.what() << "\n";
                listener.close();
            }
        }
        server_loop(listener);
    } else if (option == 2) {
        Client client;
    } else {
        cout << "Invalid input!";
    }
}
