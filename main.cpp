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


    int n;
    cin >> n;

    int arr[1001];

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; ++i) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }

    cout << arr[n];

}


