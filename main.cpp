#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, ind;
    cin >> size >> ind;

    int **arr = new int *[size]; //선언하고자 하는 이차원 배열의 행의 수 만큼 동적 할당

    for (int i = 0; i < size; i++) //각각의 인덱스에 선언하고자 하는 배열의 크기만큼을 가르키게 함.
        arr[i] = new int[size];

    for (int k = 0; k < size; ++k) {
        int a;
        cin >> a;

        if (k == 0) {
            arr[0][k] = a;
        } else {
            arr[0][k] = arr[0][k - 1] + a;
        }
    }

    for (int i = 1; i < size; ++i) {

        for (int k = 0; k < size; ++k) {
            int a;
            cin >> a;

            if (k == 0) {
                arr[i][k] = arr[i - 1][k] + a;
            } else {
                arr[i][k] = arr[i - 1][k] + arr[i][k - 1] + a - arr[i - 1][k - 1];
            }
        }

    }

    // 답 구하기
    for (int i = 0; i < ind; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1--;
        y1--;
        x2--;
        y2--;

        int a = arr[x2][y2];
        if (y1 != 0) {
            a -= arr[x2][y1 - 1];
        }
        if (x1 != 0) {
            a -= arr[x1 - 1][y2];
        }
        if (y1 != 0 && x1 != 0) {
            a += arr[x1 - 1][y1 - 1];
        }
        cout << a << "\n";
    }


}


