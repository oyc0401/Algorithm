
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int factorial(int num) {
    int sum = 1;
    for (int i = 1; i <= num; ++i) {
        sum *= i;
    }
    return sum;
}

// 1초: 1억번
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);




    int N, K;
    cin >> N >> K;

    int val = factorial(N) / factorial(K);
    val/= factorial(N-K);

    cout << val;
    return 0;
}
