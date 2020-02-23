#include <iostream>

using namespace std;

int main() {
    for (;;) {
        cout << "Options:\n";
        cout << "[1] Host a new game.\n";
        cout << "[2] Join an existing game.\n";

        int option;
        cin >> option;

        if (option == 1) {
            cout << "Starting host...\n";
            // Some code

            break;
        } else if (option == 2) {
            cout << "Enter IP of host: ";
            // Some code

            break;
        } else {
            cout << "Invalid input!";
        }
    }
}
