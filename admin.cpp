#include <iostream>
#include <string>
#include <limits>
#include <fstream>   // for saving to DB
using namespace std;

void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool askYesNo(const string& prompt) {
    char c;
    while (true) {
        cout << prompt << " (y/n): ";
        if (!(cin >> c)) { clearLine(); continue; }
        c = tolower(c);
        if (c == 'y') return true;
        if (c == 'n') return false;
        cout << "Please enter y or n.\n";
    }
}

string askLine(const string& prompt) {
    cout << prompt;
    clearLine();
    string s;
    getline(cin, s);
    return s;
}

// DB save function
void saveUserToDB(const string& name, const string& email, const string& password) {
    ofstream db("users.csv", ios::app);  // append mode
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
    cout << "Car Rental System \n";
    cout << "User type? ( 1]Admin,\n 2]Registered User,\n 3]New User\n): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: Admin(); break;          
        case 2: RegisteredUser(); break; 
        case 3: NewUser(); break;        
        default: cout << "Invalid choice\n";
    }

    cout << "\n End of Program \n";
    return 0;
}

void Admin() {
    cout << "\n Admin Login \n";
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
    cout << "\n ChooseApplication \n";
    bool running = true;

    while (running) {
        cout << "1. Update car library\n";
        cout << "2. Answer customer enquiries\n";
        cout << "3. Logout\n";
        cout << "Choose action: ";
        int ch;
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Car library updated successfully\n";
                break;
            case 2:
                cout << "Customer enquiries answered\n";
                break;
            case 3:
                cout << "Logging out\n";
                running = false;
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
}

void RegisteredUser() {
    cout << "\n Registered User \n";
    string password, correct = "2222";
    bool loggedIn = false;

    do {
        cout << "Enter password: ";
        cin >> password;

        if (password == correct) {
            cout << "Login successful\n";
            loggedIn = true;
        } else {
            cout << "Password incorrect\n";
            if (askYesNo("Forgot password?")) {
                cout << "Requesting new password\n";
                correct = askLine("Set new password: ");
                cout << "Password updated, Please login again\n";
            } else {
                cout << "Returning to login\n";
            }
        }
    } while (!loggedIn);

    cout << "Looking for desired vehicle\n";
    cout << "Making payment\n";
    cout << "Logout complete\n";
}

void NewUser() {
    cout << "\nNew User Registration \n";
    string name = askLine("Enter name: ");
    string email = askLine("Enter email: ");
    string pass  = askLine("Set password: ");

    // Save user details into DB
    saveUserToDB(name, email, pass);

    cout << "Registration Completed for " << name << ".\n";

    cout << "Proceed to login\n";
    string storedPass = pass;
    Login(storedPass);
}

void Login(string &password) {
    cout << "\nLogin \n";
    string entered;
    bool success = false;

    do {
        cout << "Enter password: ";
        cin >> entered;
        if (entered == password) {
            cout << "Login successful\n";
            success = true;
        } else {
            cout << "Incorrect password\n";
            if (askYesNo("Forgot password?")) {
                password = askLine("Set new password: ");
                cout << "Password reset successful\n";
            }
        }
    } while (!success);

    cout << "Looking for desired vehicle\n";
    cout << "Making payment\n";
    cout << "Logout complete\n";
}
