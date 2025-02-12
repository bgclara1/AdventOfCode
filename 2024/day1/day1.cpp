#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <numeric>
using namespace std;

int main() {
    ifstream read("day1Input.txt");
    vector<float> left, right, difference;
    string line;
    
    while (getline(read, line)) {
        stringstream ss(line);
        float num1, num2;

        if (ss >> num1 >> num2) {
            left.push_back(num1);
            right.push_back(num2);
        }
    }

    difference.resize(left.size());  
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    for (int i = 0; i < left.size(); i++) {
            difference[i] = abs(left[i]-right[i]);
        }

    int sumDifference = 0;
    
    sumDifference = accumulate(difference.begin(), difference.end(), 0);
    cout << sumDifference << endl;

    return 0;
}