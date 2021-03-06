#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

bool isValidNum (int x) { // checks to see if the number fits the required criteria
    bool result = true;

    string s = to_string(x);

    for (char& c : s) {
        if (c == '1' || c == '2' || c == '4' || c == '8') {
            result = false;
            break;
        }
    }

    return result;

}

int main() {

    int i = 0;
    bool numFound = false;

    while (!numFound) {
        numFound = isValidNum(pow(16,i));
        i++;
    }

    cout << "result: " << pow(16,i-1) << ", which is 16 to the power of " << i-1 << endl;

    return 0;
}