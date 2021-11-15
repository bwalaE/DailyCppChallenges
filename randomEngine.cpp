#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

using std::cout;
using std::cin;
using std::endl;

int randommer(int n) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine engS(seed); // an engine created with a seed

    //engS.min(10);

    cout << engS() << endl;

    return engS();
    
}

int main() {

    int number = 0;

    //cout << "random number is " << number << endl;
    randommer(number);

    return 0;
}