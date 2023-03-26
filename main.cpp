
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

long long mod = 1000000007;

class Matrix {
public:
    Matrix(long long a, long long b, long long c, long long d)
            : a(a), b(b), c(c), d(d) {}

    long long a, b, c, d;

    Matrix operator*(Matrix &m) {
        long long newA = a * m.a + b * m.c;
        long long newB = a * m.b + b * m.d;
        long long newC = c * m.a + d * m.c;
        long long newD = c * m.b + d * m.d;

        newA %= mod;
        newB %= mod;
        newC %= mod;
        newD %= mod;

        return Matrix{newA, newB, newC, newD};
    }

};

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    Matrix answer{1, 0, 0, 1};
    Matrix a{1, 1, 1, 0};

    while (n > 0) {
        if (n % 2 == 1)
            answer = answer * a;
        a = a * a;
        n /= 2;
    }

    cout << answer.b;


    return 0;
}


