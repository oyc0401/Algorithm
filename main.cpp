#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <cassert>

using namespace std;

//queue<int> que;
int idx;
vector<int> inOrder;
vector<int> preOrder;

void check(int start, int INSTART, int lenght) {


    if (lenght == 0) {
        return;
    } else if (lenght == 1) {
      //  que.push(preOrder[start]);
        cout<<preOrder[start]<<' ';
        ///    cout<<"큐: "<<preOrder[start]<<endl;
        return;
    }

    /// cout << start << ", " << lenght << " / " << INSTART << ", " << lenght << endl;
    int lastNumber = preOrder[start + lenght - 1];
    ///  cout << "lastNumber: " << lastNumber << endl;
    //que.push(lastNumber);
    cout<<lastNumber<<' ';

    int findLast;
    for (int i = INSTART; i < INSTART+lenght; ++i) {
        if (lastNumber == inOrder[i]) {
            ///    cout << "findLast: " << i << endl;
            findLast = i;
        }
    }

    int leftNum = findLast - INSTART;
    ///  cout << "left num: " << leftNum << endl;
    int rightNum = lenght - 1 - leftNum;
    ///   cout << "right num: " << rightNum << endl;

    ///  cout << start << ", " << leftNum << " / " << INSTART << ", " << leftNum << endl;
    ///  cout << start + leftNum << ", " << rightNum << " / " << INSTART + leftNum + 1 << ", " << rightNum << endl<<endl;
    check(start, INSTART, leftNum);
    check(start + leftNum, INSTART + leftNum + 1, rightNum);


}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> idx;


    for (int i = 0; i < idx; ++i) {
        int a;
        cin >> a;
        inOrder.push_back(a);
    }
    for (int i = 0; i < idx; ++i) {
        int a;
        cin >> a;
        preOrder.push_back(a);
    }

    check(0, 0, preOrder.size());


    // cout << "que:\n";
//    while (!que.empty()) {
//        cout << que.front() << " ";
//        que.pop();
//    }


}

// 7
// 1 3 5 2 4 6 7
// 1 5 2 3 7 6 4
