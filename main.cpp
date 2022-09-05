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

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int arr[1001][1001];

    string a, b;
    cin >> a >> b;


    int size_a = a.length();
    int size_b = b.length();

    for (int i = 0; i < size_a; ++i) {
        for (int j = 0; j < size_b; ++j) {
            if (a[i] == b[j]) {
                arr[i + 1][j + 1] = arr[i][j] + 1;
            } else {
                arr[i + 1][j + 1] = arr[i][j + 1] > arr[i + 1][j] ? arr[i][j + 1] : arr[i + 1][j];
            }
        }
    }

    //find big
    int big=0;
    for (int i = 0; i <=size_a; ++i) {
        for (int j = 0; j <= size_b; ++j) {
            //cout << arr[i][j] << " ";
            if(big<arr[i][j]){
                big=arr[i][j];
            }
        }

    }





//    /// print
//    for (int i = 0; i <=size_a; ++i) {
//        for (int j = 0; j <= size_b; ++j) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }

    cout<<big;


}
// 437674 3

// 859156 3


//ACAYKP
//CAPCA