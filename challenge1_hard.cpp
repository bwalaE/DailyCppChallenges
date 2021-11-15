#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int lowerBound = 1;
int upperBound = 100;

char userInput;

int guess() {
    int num;

    num = rand() % (upperBound - lowerBound + 1) + lowerBound;

    return num;
}

int main() {
    bool gameOver = false;
    int currentGuess;

    srand(time(NULL));

    cout << "Welcome to guessing game where I guess your number from 1 to 100." << endl;
    cout << "type 'y' if I got the answer, 'h' if the answer is higher than my guess, and 'l' if it is lower" << endl;

    while (gameOver == false) {
        currentGuess = guess();
        cout << "Let me guess, " << currentGuess << "?" << endl;

        cin >> userInput;
        switch (userInput) {
            case 'y':
                cout << "Yess got it!\nEnding game..." << endl;
                gameOver = true;
                break;
            case 'l':
                upperBound = currentGuess - 1;
                break;
            case 'h':
                lowerBound = currentGuess + 1;
                break;
            default:
                cout << "umm what? invalid input?" << endl;
        }
    }

    return 0;
}