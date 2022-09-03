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


    vector<int> vec[500];


    int ind;
    cin >> ind;

    for (int i = 0; i < ind; ++i) {
        for (int j = 0; j <= i; ++j) {
            //cout<<i<<", "<<j<<endl;
            int a;
            cin >> a;
            vec[i].push_back(a);
        }
    }
//
//    /// print
//    for (int i = 0; i < ind; ++i) {
//        for (int j = 0; j <= i; ++j) {
//            cout << vec[i][j] << " ";
//        }
//        cout << endl;
//    }


    for (int i = ind - 2; i >= 0; --i) {
       // cout << i << endl;

        for (int j = 0; j < i+1 ; ++j) {
            int front = vec[i + 1][j];
            int back = vec[i + 1][j + 1];
            //cout<<i<<", "<<j<<", "<<front<<endl;
            //vec[i][j] += front;
            vec[i][j] += front > back ? front : back;
        }
    }


//    /// print
//    for (int i = 0; i < ind; ++i) {
//        for (int j = 0; j <= i; ++j) {
//            cout << vec[i][j] << " ";
//        }
//        cout << endl;
//    }

cout<<vec[0][0];

}



