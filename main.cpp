#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[1001][3];

    int index;
    cin >> index;


    /// 입력
    for (int i = 0; i < index; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> arr[i][j];
        }
    }

    int sum[1001][3];
    for (int i = 0; i < 3; ++i) {
        sum[0][i] = arr[0][i];
    }
    /// cout << sum[0][0] << ", " << sum[0][1] << ", " << sum[0][2] << endl;

    for (int i = 1; i < index; ++i) {
        sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + arr[i][0];
        sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + arr[i][1];
        sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + arr[i][2];

        /// cout << sum[i][0] << ", " << sum[i][1] << ", " << sum[i][2] << endl;
    }

    /// cout << sum[index][0] << ", " << sum[index][1] << ", " << sum[index][2];

    int last = index - 1;
    int min1 = min(sum[last][0], sum[last][1]);
    min1 = min(min1, sum[last][2]);
    cout << min1;
}


