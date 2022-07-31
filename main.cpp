#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;


// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ind, max;

    cin >> ind >> max;
    queue<pair<int, int>> qu;
    int arr[100001];

    for (int i = 0; i < ind; ++i) {
        int a, b;
        cin >> a >> b;
        qu.push(make_pair(a, b));
    }

    // 배열 초기화
    for (int i = 0; i <= 100001; ++i) {
        arr[i] = 0;
    }

    while (!qu.empty()) {
        int weight = qu.front().first;
        int value = qu.front().second;

        queue<pair<int, int>> pushQ;

        // 이번꺼가 기존의 가치보다 클때
//        if (arr[weight] < value) {
//            arr[weight] = value;
//        }

        // 다 계산
        for (int i = 0; i <= max; ++i) {
            if(i==0){
                pushQ.push(make_pair(weight , value));
            }
            // 다음칸이 비어있지 않고
            if (arr[i] != 0) {

                // 서로 더한것이 상한 무게를 초과하지 않고
                if (weight + i <= max) {

                    pushQ.push(make_pair(weight + i, value + arr[i]));

                }

            }
        }


        while (!pushQ.empty()) {
            if (arr[pushQ.front().first] < pushQ.front().second) {
                arr[pushQ.front().first] = pushQ.front().second;
            }
            pushQ.pop();
        }



//        /// print
//        for (int i = 1; i <= max; ++i) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;

        qu.pop();

    }


    int big = 0;
    for (int i = 1; i <= max; ++i) {
        if (arr[i] > big) {
            big = arr[i];
        }
    }

    cout << big;

}

//7 7
//6 13
//4 8
//3 6
//5 12
//4 9
//4 9
//2 4

//4 7
//3 4
//1 1
//2 1
//1 2