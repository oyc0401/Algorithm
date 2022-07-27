
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ind;
    cin >> ind;
    priority_queue<int, vector<int>, less<int>> que;
    for (int i = 0; i < ind; ++i) {
        int num;
        cin >> num;
        if (num == 0) {
            if (que.empty()) {
                cout << 0 << '\n';
            } else {
                cout << que.top() << '\n';
                que.pop();
            }
        } else {
            que.push(num);
        }
    }

    return 0;
}


