#include <iostream>
#include "server.h"
#include "client.h"
#include "server_logic.h"
#include "client_logic.h"

using namespace std;

int main() {
    while (true) {
        cout << "Options:\n";
        cout << "[1] Host a new game.\n";
        cout << "[2] Join an existing game.\n";
        cout << "[3] Quit.\n";
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
            while (true) {
                string server_address;
                int server_port;

                cout << "Enter server address: ";
                cin >> server_address;
                cout << "Enter server port: ";
                cin >> server_port;

                cout << "Attempting to connect to server...\n";
                try {
                    client.create();
                    client.connect(server_address, server_port);

                    cout << "Connected to server.\n";
                    break;
                } catch (SocketException &e) {
                    cout << "Error: " << e.what() << "\n";
                    client.close();
                }
            }
            client_loop(client);
        } else if (option == 3) {
            break;
        } else {
            cout << "Invalid input!";
        }
    }
}
