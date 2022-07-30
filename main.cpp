#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


int a, b;

void print(int n, string text, int depth) {

    for (int i = n; i <= a; ++i) {
        // cout << "def: " << def << ", n: " << n << endl;
        string te = text + to_string(i) + " ";

        if (depth == b) {
            cout << te << endl;
        } else {
            print(i + 1, te, depth + 1);
        }
    }
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> a >> b;

    print(1, "", 1);

}
