#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

int farr[1001][1001];
int arr[1001][1001];

//50: 177777414, 97354

int fsize(int n) {

    for (int i = 2; i <= n; ++i) {
        int a = i;
        int b = 0;
        while (a >= 0) {
            if (a == 0 || b == 0) {
                farr[a][b] = 1;
            } else {
                int val = farr[a - 1][b] * (a + b) / a;
                farr[a][b] = val;
            }

            a -= 2;
            b += 1;
        }

    }
    int a = n;
    int b = 0;
    int sum = 0;

    while (a >= 0) {
        /// cout << farr[a][b] << " ";
        a -= 2;
        b += 1;
    }
    /// cout << endl;

    a = n;
    b = 0;
    sum = 0;

    while (a >= 0) {
        /// cout << farr[a][b] % 10007 << " ";
        sum += farr[a][b] % 10007;
        a -= 2;
        b += 1;
    }
    /// cout << endl;

    return sum;
}


int size(int n) {

    for (int i = 2; i <= n; ++i) {
        int a = i;
        int b = 0;
        while (a >= 0) {
            if (a == 0 || b == 0) {
                arr[a][b] = 1;
            } else {
                int val = arr[a - 1][b] * (a + b) / a;

                arr[a][b] = val;
                arr[a][b] = val % 10007;
            }

            a -= 2;
            b += 1;
        }

    }

    int a = n;
    int b = 0;
    int sum = 0;

    while (a >= 0) {
        /// cout << arr[a][b] << " ";
        sum += arr[a][b];
        a -= 2;
        b += 1;
    }
    /// cout << endl;


    return sum % 10007;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        cout<<i<<": \n";

        int f = fsize(i);
        int s = size(i);

        cout << f << ", " << f % 10007 << endl << s<<endl;
    }




}


