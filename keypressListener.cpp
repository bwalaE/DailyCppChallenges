/*
    This program shows how to use a keypress listener.
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main() {

    char key;
    int asciiValue;

    cout << "press a key to see its ASCII value\nPress ESC to quit\n" << endl;

    while(1) {
        key=getch();
        asciiValue=key;

        if (asciiValue == 27) {
            break;
        }

        cout << "Key pressed -> " << key << ". ASCII value: " << asciiValue << endl;
    }
    return 0;
}