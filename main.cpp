#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

void printStar(int level, int row) {

    if (level == 1) {
        if (row == 1) {
            cout << "***";
        } else if (row == 2) {
            cout << "* *";
        } else {
            cout << "***";
        }
    } else {
        // 123 456 789
        int countHalf = pow(3, level) / 3;

        // 중간 부분
        if (countHalf < row && row <= countHalf * 2) {

            printStar(level - 1, row - countHalf);

            for (int k = 1; k <= countHalf; ++k) {
                cout << ' ';
            }

            printStar(level - 1, row - countHalf);

        } else {

            for (int i = 0; i < 3; ++i) {
                printStar(level - 1, row % countHalf);
            }
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

    int val = row;
    int level = 0;

    // val이 3^2 이면 level=2;
    while (val != 1) {
        val /= 3;
        level++;
    }


    //int testL = 2;
    //int testR = 3 * pow(2, testL);


    //cout << level;

    for (int i = 1; i <= row; ++i) {
        printStar(level, i);
        cout << '\n';
    }

}
