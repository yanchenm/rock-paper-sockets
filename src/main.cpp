#include <iostream>
#include "Server.h"
#include "Client.h"
#include "server_logic.h"

using namespace std;

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
        string roomID;
        cout << "Enter your room ID: ";
        cin >> roomID;


    } else {
        cout << "Invalid input!";
    }
}
