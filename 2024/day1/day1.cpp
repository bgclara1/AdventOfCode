#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string text;

    ifstream read("day1Input.txt");
    vector<float> input;
    int i = 0;
    while(getline (read, text)) {
        input.push_back(stof(text));
    }

    read.close();


    vector<float> left;
    vector<float> right;
    int n = 1;
    int m = 1;
    for (int i = 1; i < input.size()+1; i++) {
        if (i%2 == 1) {
            left[n] = input[i];
            cout << left[n] << endl;
            n++;
        } else {
            right[m] = input[i];
            m++;
        }

        }

    cout << "Left:" << endl;

    for (float element: left) {
        cout << element << endl;
    }

    cout << "Right:" << endl;

    for (float element: right) {
        cout << element << endl;
    }
}