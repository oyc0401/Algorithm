#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


int a, b;
vector<int> vec;
vector<int> sta;

void print(int depth) {


    for (int i = 0; i < a; ++i) {
        // cout << "depth: " << depth << ", i: " << i << endl;

        // 이미 배열에 i 값이 존재하면 건너뛰기
        bool empty = true;
        for (int num: sta) {
            if (num == i) {
                empty = false;
            }
        }

        sta.push_back(i);

        if (empty) {
            if (depth == b) {
                // cout << te << endl;
                for (int num: sta) {
                    cout << vec[num] << " ";
                }
                cout << "\n";

            } else {
                print(depth + 1);

            }
        }

        sta.pop_back();
    }

}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> a >> b;

    for (int i = 0; i < a; ++i) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    std::sort(vec.begin(), vec.end());

    print(1);

}
