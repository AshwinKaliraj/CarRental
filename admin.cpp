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