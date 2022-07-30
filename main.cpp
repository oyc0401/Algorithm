#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

//string star[11][3072]{"  *  ", " * * ", "*****"};
//void setStar(int level) {
//    int count = 3 * pow(2, level);
//
//    // 위 부분
//    for (int i = 0; i < count / 2; ++i) {
//        string tex;
//        for (int j = 0; j < count / 2; ++j) {
//            tex = tex + " ";
//        }
//        tex = tex + star[level - 1][i];
//        for (int j = 0; j < count / 2; ++j) {
//            tex = tex + " ";
//        }
//        star[level][i] = tex;
//    }
//
//    // 아래부분
//    for (int i = 0; i < count / 2; ++i) {
//        string tex = star[level - 1][i] + " " + star[level - 1][i];
//        star[level][i + (count / 2)] = tex;
//    }
//}


void printStar(int level, int row) {

    if (level == 0) {
        if (row == 1) {
            cout << "  *  ";
        } else if (row == 2) {
            cout << " * * ";
        } else {
            cout << "*****";
        }
    } else {
        int countHalf = 3 * pow(2, level) / 2;

        // 윗 부분
        if (row <= countHalf) {
            for (int k = 1; k <= countHalf; ++k) {
                cout << ' ';
            }
            printStar(level - 1, row);
            for (int k = 1; k <= countHalf; ++k) {
                cout << ' ';
            }
        } else {
            // 아랫부분
            printStar(level - 1, row - countHalf);
            cout << ' ';
            printStar(level - 1, row - countHalf);
        }
    }
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row;
    cin >> row;

    int two = row / 3;
    int level = 0;
    while (two != 1) {
        two /= 2;
        level++;
    }


    //int testL = 2;
    //int testR = 3 * pow(2, testL);


    for (int i = 1; i <= row; ++i) {
        printStar(level, i);
        cout << '\n';
    }

}
