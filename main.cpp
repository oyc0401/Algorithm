
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <sstream>

using namespace std;

int plusNum = 0;
int minusNum = 0;

vector<string> plusSplit(string text, char div) {
    istringstream ss(text);
    string stringBuffer;
    vector<string> vec;
    vec.clear();

    // 자르기
    while (getline(ss, stringBuffer, div)) {
        vec.push_back(stringBuffer);
        plusNum++;
    }
    plusNum--;
    return vec;
}

vector<string> minusSplit(string text, char div) {
    istringstream ss(text);
    string stringBuffer;
    vector<string> vec;
    vec.clear();

    // 자르기
    while (getline(ss, stringBuffer, div)) {
        vec.push_back(stringBuffer);
        minusNum++;
    }
    minusNum--;
    return vec;
}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text;
    cin >> text;

    vector<string> vec = plusSplit(text, '-');


    int sum = 0;

    bool first = true;
    for (string t: vec) {


        int plus = 0;
        vector<string> vecPlus = minusSplit(t, '+');
        for (string n: vecPlus) {
            int num = stoi(n);
            plus += num;
        }

        if (first) {
            sum += plus;
            first = false;
        } else {
            sum -= plus;
        }

        //cout << plus << endl;


    }


    //cout<<"답: "<<sum<<endl;
    cout << sum;

    return 0;
}


