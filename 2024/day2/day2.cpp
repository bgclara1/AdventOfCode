#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("day2input.txt");

    vector<vector<int> > allData; 
    string lines;

    while (getline(inputFile, lines)) {

        istringstream iss(lines);
        vector<int> rowInts;
        int value;
        while (iss >> value) {
            rowInts.push_back(value);
        }
        allData.push_back(rowInts);
    }
    inputFile.close();

    for (size_t i = 0; i < allData.size(); i++) {
        for (size_t j = 0; j < allData[i].size(); j++) {
    //        cout << allData[i][j] << " ";
        }
      //  cout << endl;
    }

    vector<int> line;
    int numsafe = 0;

    for (size_t i = 0; i < allData.size(); i++) {
        bool incr = false;
        bool decr = false;
        bool safe = false;
        bool unsafe = false;
        if (allData[i][1]-allData[i][0] > 0) {
                incr = true;
            } else {
                decr = true;
            }
        for (size_t j = 0; j < allData[i].size()-1; j++) {
            if (allData[i][j+1] - allData[i][j] >= 0 && decr == true) {
                unsafe = true;
            } else if (allData[i][j+1] - allData[i][j] <= 0 && incr == true) {
                unsafe = true;
            } else if (abs(allData[i][j+1] - allData[i][j]) > 3 ) {
                unsafe = true;
            } else if (allData[i][j+1] == allData[i][j]) {
                unsafe = true;
            }
        }

        if (unsafe == false) {
            numsafe += 1;

        }
    }

    cout << numsafe << endl;






    return 0;
}

