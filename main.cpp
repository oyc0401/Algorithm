#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int Million = 1000000;

    unsigned long long int n;
    cin >> n;

    n %= 1500000;

    int first = 1;
    int second = 0;
    int third = 1;

    for ( int i = 1; i <= n; ++i) {
        third = (first + second) % Million;
        first = second;
        second = third;
    }

    cout << second % Million;

}


