#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

vector<int> myVec;

int lastIdx(int target) {
    int size = myVec.size();
    int left = 0;
    int right = size - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

//        cout << left << ", " << mid << ", " << right << endl;

        if (myVec[mid] > target) {
            // 다운
            right = mid - 1;
        } else if (myVec[mid] < target) {
            // 업
            left = mid + 1;
        } else {
            left = mid;
            break;
        }
    }

//    cout<<"리턴: "<<left<<endl;
    return left;
}
// 0 9
// 1 3 6 8 10 13 17 18 20

int minNum = -1'000'000'001;

// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int idx;
    cin >> idx;
    queue<int> que;

    myVec.push_back(minNum);

    for (int i = 0; i < idx; ++i) {
        int a;
        cin >> a;
        que.push(a);
    }

    while (!que.empty()) {

        /// cout<<qu.front()<<":\n";

        int cur = que.front();
        int last = lastIdx(cur);
//        cout<<last<<endl;

        if (myVec.size() <= last) {
            myVec.push_back(que.front());
        } else {
            myVec[last] = que.front();
        }



//        /// print
//        for (int i = 0; i < myVec.size(); ++i) {
//            cout << "(" << i << ", " << myVec[i] << ") ";
//        }
//        cout << endl;

        que.pop();

    }


    cout << myVec.size() - 1 << endl;

//    for (int n: myVec) {
//        if (n != minNum) {
//            cout << n << " ";
//        }
//
//    }

}

//12
//1 2 10 10 11 99 13 14 3 4 5 6

/// 3 6 5 7 8 3 2 7 9 1 5 7 4 2 9 8 2 3 4 8 7 9
