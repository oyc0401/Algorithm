#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;

    cin >> A >> B >> V;

    V -= A;

    if (V < 0) {
        cout << 1;
    }


    int day = (V / (A - B)) + 1;
    if ((V % (A - B)) != 0) {
        day++;
    }

    cout << day << endl;


}
