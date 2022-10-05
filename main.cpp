
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;
int **arr;
int mi = 0;
int ze = 0;
int one = 0;

void check(int x, int y, int size) {
    int first = arr[x][y];
    // cout << x << ", " << y << ", " << size << endl;
    for (int i = x; i < size + x; ++i) {
        for (int j = y; j < size + y; ++j) {
            if (arr[i][j] != first) {
                int si = size / 3;
                int a = x / 3;
                int b = y / 3;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        check(x + si * k, y + si * l, si);
                    }
                }
                return;
            }
        }
    }

    if (first == -1) {
        mi++;
    } else if (first == 0) {
        ze++;
    } else if (first == 1) {
        one++;
    }

}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index;
    cin >> index;

    arr = new int *[index];
    for (int i = 0; i < index; ++i) {
        arr[i] = new int[index];
    }

    for (int i = 0; i < index; ++i) {
        for (int j = 0; j < index; ++j) {
            cin >> arr[i][j];
        }
    }

    check(0, 0, index);

    cout << mi << endl;
    cout << ze << endl;
    cout << one;


    return 0;
}


