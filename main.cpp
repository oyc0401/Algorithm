
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int row, col, recSize=0;
int number = 0;

void cut() {
    // 넓이 1/4 감소
    recSize /= 2;
    int where;

    if (col < recSize) {
        //cout << "왼쪽\n";
        if (row < recSize) {
           // cout << "위쪽\n";
            where = 0;
        } else {
            // cout << "아래쪽\n";
            where = 2;
            row -= recSize;
        }
    } else {
        // cout << "오른쪽\n";
        if (row < recSize) {
           // cout << "위쪽\n";
            where = 1;
        } else {
            // cout << "아래쪽\n";
            where = 3;
            row -= recSize;
        }
        col -= recSize;
    }

    number += recSize * recSize * where;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        
    }
    recSize = pow(2, N);

    cin >> row >> col;

    while (recSize != 1) {
        cut();
        // cout << row << ", " << col << ", " << recSize <<", " << number<<endl;
    }

    cout << number;

    return 0;
}


