#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target, ind;
    cin >> target >> ind;
    vector<int> vec;
    for (int i = 0; i < ind; ++i) {
        int n;
        cin >> n;
        vec.push_back(n);
    }

    int minClick=abs(100 - target);

    for (int i = 0; i <= 1000000; ++i) {
        string text = to_string(i);

        bool canShow = true;
        for (int n: vec) {
            if (text.find(to_string(n)) != std::string::npos) {
                canShow = false;
            }
        }

        if (canShow && abs(i - target)+to_string(i).size() < minClick) {
           /// cout << i << '\n';
            minClick=abs(i - target)+to_string(i).size();
        }
    }
    ///cout << '\n';
    ///cout<<to_string(number).size()<<'\n';
    ///cout << minDistance<<'\n';

    cout<<minClick;

}
//105
//10
//0 1 2 3 4 5 6 7 8 9