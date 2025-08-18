#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void DB(const string& name, const string& email, const string& password) {
    ofstream db("users.csv", ios::app);
    if (!db) {
        cerr << "Error opening users.csv!\n";
        return;
    }
    db << name << "," << email << "," << password << "\n";
    db.close();
    cout << "User details saved in DB (users.csv)\n";
}

void Admin();
void ChooseApplication();
void RegisteredUser();
void Login(string &password);
void NewUser();

int main() {
    cout << "Car Rental System\n";
    cout << "User type? 1]Admin, 2]Registered User, 3]New User\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: Admin(); break;
        case 2: RegisteredUser(); break;
        case 3: NewUser(); break;
        default: cout << "Invalid choice\n";
    }

    cout << "\nEnd of Program\n";
    return 0;
}

void Admin() {
    cout << "\nAdmin Login\n";
    string password, correct = "111";
    bool loggedIn = false;

    do {
        cout << "Enter admin password: ";
        cin >> password;
        if (password == correct) {
            cout << "Login successful\n";
            loggedIn = true;
        } else {
            cout << "Login failed\n";
        }
    } while (!loggedIn);

    ChooseApplication();
}

void ChooseApplication() {
    cout << "\nChooseApplication\n";
    bool running = true;

    while (running) {
        cout << "1. Update car library\n";
        cout << "2. Answer customer enquiries\n";
        cout << "3. Logout\n";
        cout << "Choose action: ";
        int ch;
        cin >> ch;

        switch (ch) {
            case 1: cout << "Car library updated successfully\n"; break;
            case 2: cout << "Customer enquiries answered\n"; break;
            case 3: cout << "Logging out\n"; running = false; break;
            default: cout << "Invalid choice\n";
        }
    }
}

void RegisteredUser() {
    cout << "\nRegistered User\n";
    string password, correct = "2222";
    bool loggedIn = false;
    char choice;

    do {
        cout << "Enter password: ";
        cin >> password;

        if (password == correct) {
            cout << "Login successful\n";
            loggedIn = true;
        } else {
            cout << "Password incorrect\n";
            cout << "Forgot password? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cout << "Set new password: ";
                cin >> correct;
                cout << "Password updated, Please login again\n";
            }
        }
    } while (!loggedIn);

    cout << "Looking for desired vehicle\n";
    cout << "Making payment\n";
    cout << "Logout complete\n";
}

void NewUser() {
    cout << "\nNew User Registration\n";
    string name, email, pass;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter email: ";
    cin >> email;
    cout << "Set password: ";
    cin >> pass;

    DB(name, email, pass);

    cout << "Registration Completed for " << name << "\n";
    cout << "Proceed to login\n";

    string storedPass = pass;
    Login(storedPass);
}

void Login(string &password) {
    cout << "\nLogin\n";
    string entered;
    bool success = false;
    char choice;

    do {
        cout << "Enter password: ";
        cin >> entered;
        if (entered == password) {
            cout << "Login successful\n";
            success = true;
        } else {
            cout << "Incorrect password\n";
            cout << "Forgot password? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cout << "Set new password: ";
                cin >> password;
                cout << "Password reset successful\n";
            }
        }
    } while (!success);

    cout << "Looking for desired vehicle\n";
    cout << "Making payment\n";
    cout << "Logout complete\n";
}
