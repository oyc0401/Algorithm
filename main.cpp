#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <stack>
#include <cstdlib>

using namespace std;

// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;
    vector<vector<int>> node(nodeCount);

    vector<int> vec(nodeCount);

    for (int i = 0; i < edgeCount; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        node[a].push_back(b);
        vec[b]++;
    }

    queue<int> que;
    for (int i = 0; i < nodeCount; ++i) {
        if (vec[i] == 0) {
            que.push(i);
            vec[i] = -1;
        }
    }


    while (!que.empty()) {
        int front = que.front();

        for (int n: node[front]) {
            vec[n]--;
            if (vec[n] == 0) {
                que.push(n);
                vec[n] = -1;
            }
        }

        cout << front + 1 << " ";
        que.pop();
    }


}
