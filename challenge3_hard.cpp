#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout, std::cin, std::endl, std::string, std::ifstream, std::vector, std::getline;

int index;
string unscrambled;

string arrangeString(string str) { //this function works
    // arranges the chars in a string in alphabetical order
    char temp;
    int i, j;
    int n = str.length();
    for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (str[i] > str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}	
	}
    return str;
}

bool compareStringToFile(string path, string s1) {
    ifstream file1 (path);
    string lineHolder;
    string strArranged = arrangeString(s1);
    int indexA = 0;

    while (getline(file1, lineHolder)){
        //this code runs for every line in the txt file
        indexA++;
        if (arrangeString(lineHolder) == strArranged) {
            unscrambled = lineHolder;
            index = indexA;
            return true;
        } else {
            continue;
        }
    }

    file1.close();
    // if something went wrong and the program didn't get through the file
    return false;
}

void compareStringVectorToFile(string path, vector<string> &v1) {
    ifstream file1;
    string lineHolder;
    string strArranged;

    for (string& s : v1) {
        file1.open(path);
        strArranged = arrangeString(s);
        while (getline(file1, lineHolder)){
            //this code runs for every line in the txt file
            if (arrangeString(lineHolder) == strArranged) {
                s = lineHolder;
                continue;
            } else {
                continue;
            }
        }
        file1.close();
    }  
}

int main() {

    //testing the singular string version of the function
    /*string userinput;

    cout << "enter a string to see if it is in the list: ";
    cin >> userinput;

    if (!compareStringToFile("fstreamFiles/challenge3.txt", userinput)) {
        cout << "not in the list" << endl;
    }
    else {
        cout << "success, in the list" << endl;
        cout << "Your entry, '" << userinput << "' is equal to '" << unscrambled << "', located at position " << index << endl;
    }*/

    //testing the vector version
    vector<string> linesToTest;
    linesToTest.push_back("mkeart");
    linesToTest.push_back("sleewa");
    linesToTest.push_back("edcudls");
    linesToTest.push_back("iragoge");
    linesToTest.push_back("usrlsle");
    linesToTest.push_back("nalraoci");
    linesToTest.push_back("nsdeuto");
    linesToTest.push_back("amrhat");
    linesToTest.push_back("inknsy");
    linesToTest.push_back("iferkna");

    compareStringVectorToFile("fstreamFiles/challenge3.txt", linesToTest);
    for (string& s : linesToTest) {
        cout << s << endl;
    }
    
    return 0;
}