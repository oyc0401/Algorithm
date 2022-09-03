#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>
#include<sstream>

using namespace std;


vector<string> split(string text, char div) {
    istringstream ss(text);
    string stringBuffer;
    vector<string> vec;
    vec.clear();

    // 자르기
    while (getline(ss, stringBuffer, div)) {
        vec.push_back(stringBuffer);
    }
    return vec;
}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<string> x = split("kakao naver google", ' ');

    cout << endl << "vector 값을 출력해보자." << endl;

    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << endl;
    }

}


