#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <cassert>

using namespace std;

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx;
    cin >> idx;
    for (int i = 0; i < idx; ++i) {
        int Ax, Ay, Bx, By, d1, d2;
        cin >> Ax >> Ay >> d1 >> Bx >> By >> d2;

        int a = Ax - Bx;
        int b = Ay - By;
        int bitween = (a * a + b * b);

        int big = d1 > d2 ? d1 : d2;
        int small = d1 < d2 ? d1 : d2;

        int sum = big * big + 2 * big * small + small * small;
        int minus = big * big - 2 * big * small + small * small;

//        cout << bitween << ", " << a << ", " << b << endl;
//        cout << bitween << ", " << big << ", " << small << endl;
//        cout << bitween << ", " << sum << ", " << minus << endl;

        if (Ax == Bx && Ay == By && d1 == d2) {
            cout << -1 << '\n';
        } else if (bitween == sum || bitween == minus) {
            cout << 1 << '\n';
        } else if (minus < bitween && bitween < sum) {
            cout << 2 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }


//    if ((a * a + b * b) < (d1 * d1 + d2 * d2))


}
//3
//0 0 13 40 0 37
//0 0 3 0 7 4
//1 1 1 1 1 5
//0 0 2 0 0 2
//0 0 2 0 0 4
//0 0 7 0 4 3
//0 0 7 0 4 4
//4 3 5 12 9 5

