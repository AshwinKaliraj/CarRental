#include <iostream>
#include <string>
#include <limits>
#include <fstream>  
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
        cout << "Please enter y or n\n";
    }
}

string askLine(const string& prompt) {
    cout << prompt;
    clearLine();
    string s;
    getline(cin, s);
    return s;
}
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
void AdminActions();
void RegisteredUser();
void Login(string &password);
void NewUser();

int main() {
    cout << "Car Rental System \n";
    cout << "User type? (1=Admin\n, 2=Registered User\n, 3=New User): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: Admin();
        break;          
        case 2: RegisteredUser(); 
        break; 
        case 3: NewUser(); 
        break;        
        default: cout << "Invalid choice\n";
    }

    cout << "\n End of Program \n";
    return 0;
}