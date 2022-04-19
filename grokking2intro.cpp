#include <iostream>
#include <array>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main() {

    std::array<int, 9> arr1 = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k;
    int sumOfKNums = 0;

    cout << "Enter k: ";
    cin >> k;

    int numOfAvgs = arr1.size() - k + 1;
    std::vector<double> avgsVector;

    //cout << numOfAvgs << endl;

    for (int i=0; i<arr1.size(); i++) { //this loop runs once for each element in arr1
        if (i+k > arr1.size()) {
            //this successfully breaks the loop at the appropriate time
            //cout << "break" << endl;
            break;
        }
        for (int j=0; j<k; j++) { //this loop runs for each
            sumOfKNums += arr1[i+j];
        }
        //cout << (double)sumOfKNums / k << endl;
        avgsVector.push_back((double)sumOfKNums / k);
        sumOfKNums = 0;
    }

    //print the list of averages
    for (int i=0; i<avgsVector.size(); i++) {
        cout << avgsVector[i];
        if (i != avgsVector.size()-1) {
            cout << ", ";
        }
    }

    return 0;
}