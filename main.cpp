#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ind;
    cin >> ind;

    vector<int> vec;


    for (int i = 0; i < ind; ++i) {
        int a;
        cin >> a;
        vec.push_back(a);
    }


    std::sort(vec.begin(), vec.end());


    int current = 0;
    int sum = 0;

    for (int time: vec) {
        current += time;
        // cout << current << " ";

        sum += current;
    }

    cout << sum;


    return 0;
}


