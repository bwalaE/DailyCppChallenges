#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <conio.h>

using namespace std;

struct mLap {
    int number;
    double time;
};

bool programRunning; // whether the program is running
bool watchRunning; // whether the stopwatch is running
char key; // the key that was pressed
double timeElapsed; //the time in the current lap
int currentLapNum; // the number of the lap currently being recorded
mLap currentLap; //the current lap

vector<mLap> lapList; //the list of laps

//vector<mLap> dummyLapList; // a dummy lap list, comment out later

chrono::steady_clock::time_point pStart;
chrono::steady_clock::time_point pEnd;
chrono::steady_clock::duration d;

/*void populateDummyLapList() {
    mLap l1,l2,l3;
    l1.number = 1;
    l2.number = 3;
    l3.number = 6;
    l1.time = 1.2;
    l2.time = 2.4;
    l3.time = 5.7;
    dummyLapList.push_back(l1);
    dummyLapList.push_back(l2);
    dummyLapList.push_back(l3);
    //cout << "populateDummyLapList ran" << endl;
}*/

void printLapList(vector<mLap> lList) {
    cout << "Lap list:" << endl;
    for (int i = 0; i < lList.size(); i++) {
        cout << "lap " << lList[i].number << ": " << lList[i].time << "s" << endl;
    }
    //cout << "printLapList ran" << endl;
}

void saveLapList(vector<mLap> lList) {
    cout << "Saving race to file..." << endl;

    //creates a blank text file
    ofstream file ("fstreamFiles/hiscores.txt");

    for (int i = 0; i < lList.size(); i++) {
        file << "Lap" << lList[i].number << ": " << lList[i].time << "s" << endl;
    }

    file.close();
}

int main () {

    programRunning = true;
    watchRunning = false;
    currentLapNum = 1;

    cout << "Hit 's' to start/stop the timer, 'l' to lap while running, and 'q' to quit." << endl;

    while (programRunning) {

        key = getch();
        lapList.clear();

        // q or ESC clicked, user quitting
        if (key == 113 || key == 27) {
            
            cout << "Quitting..." << endl;
            programRunning = false;
        }

        // s clicked, watch started
        else if (key == 115) {
            // there are two ways I thought of doing this, I commented out the one below to try one with a nested while loop
            /*if (watchRunning == false) { // the watch is not running, so s starts it
                watchRunning = true;

            } else {                     // the watch is running, so s pauses it
                watchRunning = false;
            }*/

            watchRunning = true;
            pStart = chrono::steady_clock::now();
            cout << "Timer running..." << endl;

            while (watchRunning) {

                key = getch();

                // q or ESC clicked, user quitting
                if (key == 113 || key == 27) {
                    cout << "Quitting..." << endl;
                    watchRunning = false;
                    programRunning = false;
                }

                // s clicked, watch stopped
                else if (key == 115) {

                    pEnd = chrono::steady_clock::now();
                    d = pEnd - pStart;

                    cout << "Timer stopped." << endl;
                    timeElapsed = chrono::duration_cast<chrono::milliseconds>(d).count();
                    timeElapsed = timeElapsed / 1000;
                    //cout << "Elapsed time: " << timeElapsed << "s" << endl;

                    //adding the lap to the list
                    currentLap.number = currentLapNum;
                    currentLap.time = timeElapsed;
                    lapList.push_back(currentLap);

                    saveLapList(lapList);

                    currentLapNum = 1;
                    watchRunning = false;
                }
                
                // l clicked, lapping
                else if (key == 108) {

                    pEnd = chrono::steady_clock::now();
                    d = pEnd - pStart;

                    cout << "lapped" << endl;
                    timeElapsed = chrono::duration_cast<chrono::milliseconds>(d).count();
                    timeElapsed = timeElapsed / 1000;

                    //adding the lap to the list
                    currentLap.number = currentLapNum;
                    currentLap.time = timeElapsed;
                    lapList.push_back(currentLap);

                    // clearing the current lap
                    currentLap.number = 0;
                    currentLap.time = 0;

                    //reset the timer
                    pStart = chrono::steady_clock::now();

                    currentLapNum++;
                }

                else {
                    cout << "Hmm?" << endl;
                }
            }
        }

        //user input 't' for tests
        else if (key == 116) {
            //saveLapList(lapList);
            cout << "test input" << endl;
        }

        //invalid input handler
        else {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}