
#include <iostream>
#include <map>
#include <iomanip>
#include "vector"

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> scores;

    double big = 0;
    for (int i = 1; i <= num; i++) {
        int score;
        cin >> score;
        scores.push_back(score);
        if (big < score) {
            big = score;
        }
    }

    double sum = 0;
    for (int sc: scores) {
        sum += (sc/big)*100;
    }


    cout << fixed<< setprecision(10) << sum/num;
    return 0;
}

