#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <numeric>
using namespace std;

int simScore(vector<int> left, vector<int> right) {
    int sim = 0;

    for (int i = 0; i < left.size(); i++) {
        int count = 0; 
        for (int j = 0; j < right.size(); j++) {
            if (left[i] == right[j]) {
                count++;
            }
        }
        sim += left[i] * count;
    }

    return sim;
}

int main() {
    ifstream read("day1Input.txt");
    vector<int> left, right, difference;
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
    cout << "Part A Answer: " << endl;
    cout << sumDifference << endl;

    cout << "Part B Answer: " << endl;
    
    int partB = simScore(left, right);
    cout << partB << endl;

    return 0;
}