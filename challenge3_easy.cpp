#include <iostream>

using std::cout, std::cin, std::endl, std::string; //apparently this syntax only works in C++17 and after?

string userinput;

string cipherString(string str) {
    string strCiphered = "";
    
    //iterate through string
    for (char& c : str) {
        if (c < 100) { // c is below 'd'
            strCiphered.push_back(char(c + 23));
        }
        else { // c is 'd' or higher
            strCiphered.push_back(char(c - 3));
        }
    }

    return strCiphered;
}

int main() {

    cout << "Enter the string to be ciphered (lowercase letters only): ";
    cin >> userinput;
    cout << "Ciphered string: " << cipherString(userinput) << endl;

    return 0;
}