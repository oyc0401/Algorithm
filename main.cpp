#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;
int x, y, inventory;
int **arr;

int MAX=1000000000;

int dig(int height) {


    int inven = inventory;
    int time = 0;


    for (int i = 0; i < y; ++i) {
        for (int k = 0; k < x; ++k) {
            if (arr[i][k] < height) {
                // 땅이 낮으면 설치
                inven -= height - arr[i][k];
                time += height - arr[i][k];
            } else if (arr[i][k] > height) {
                // 땅이 높으면 부수기
                inven += arr[i][k] - height;
                time += (arr[i][k] - height) * 2;
            }
        }
    }
    if (inven < 0) {
        time = MAX;
    }
    return time;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> y >> x >> inventory;


    arr = new int *[y]; //행의 크기가 3인 이차원 배열
    for (int i = 0; i < y; i++) //각각의 행에 길이가 4인 배열을 할당
        arr[i] = new int[x];


    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            cin >> arr[i][j];
        }
    }


    int minTime = MAX;
    int high = 0;

    for (int i = 0; i < 300; ++i) {
        int t = dig(i);
        if (minTime >= t) {
            minTime = t;
            high = i;
        }
        //cout << t << " " << i << endl;

//        if(t==MAX){
//            break;
//        }

    }

    cout<<minTime<<" "<<high;




//    /// print
//    for (int i = 0; i < y; ++i) {
//        for (int j = 0; j < x; ++j) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }


}
//3 4 0
//64 64 64 64
//64 64 64 64
//64 64 64 63

//3 4 99
//0 0 0 1
//0 0 0 1
//0 0 1 1