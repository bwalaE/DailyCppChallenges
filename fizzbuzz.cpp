#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void remainderTest() {
    cout << 14%2 << endl;
}

int main() {

    //remainderTest();

    int n = 31;

    for (int i=1; i<=n; i++) {
        if (i%3 == 0 && i%5 == 0) { // i is divisible by 3 AND 5
            cout << "FizzBuzz" << endl;
        }
        else if (i%5 == 0) {
            cout << "Buzz" << endl;
        }
        else if (i%3 == 0) {
            cout << "Fizz" << endl;
        }
        else {
            cout << i << endl;
        }
    }

    return 0;
}