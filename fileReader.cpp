/*
    This program reads lines from a text file and then outputs them
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout, std::endl, std::string, std::ifstream, std::vector, std::getline;

void readFromFile(string path, vector<string> &v1) {
    ifstream file1 (path);
    string lineHolder;

    while (getline(file1, lineHolder)){
        v1.push_back(lineHolder);
    }

    file1.close();
}

void printLines(vector<string> v1) {
    for (string s : v1) {
        cout << s << endl;
    }
}

int main() {

    //cout << "program start" << endl;

    string path1 ("fstreamFiles/test1.txt");
    vector<string> linesFromFile;

    readFromFile(path1, linesFromFile);
    printLines(linesFromFile);
    
    return 0;
}