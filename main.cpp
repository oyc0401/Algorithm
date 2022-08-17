#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

vector<int> arr[101];
int dist[101][101];
int INF = 1000000;

int cn(int num) {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            dist[i][j] = INF;
        }
    }

    queue<int> que;
    que.push(num);
    dist[num][num] = 0;


    while (!que.empty()) {
        for (int n: arr[que.front()]) {
            //cout << n << endl;
            if (dist[num][n] > dist[num][que.front()] + 1) {
                dist[num][n] = dist[num][que.front()] + 1;
                que.push(n);
            }
        }

        que.pop();
    }

    int sum = 0;

    for (int a: dist[num]) {
        if (a != INF) {
            sum += a;
        }
    }
    return sum;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int node, edge;
    cin >> node >> edge;

    vector<int> vec;
    for (int i = 0; i < edge; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    int small =INF;
    int person = 0;

    for (int i = 1; i <= node; ++i) {
        int sum = cn(i);
        if (small > sum) {
            small = sum;
            person = i;
        }
//        cout << cn(i) << endl;
//        for (int k = 0; k < 100; ++k) {
//            cout << dist[i][k] << " ";
//        }
//        cout << endl;
    }

    cout<<person;

}
//105
//10
//0 1 2 3 4 5 6 7 8 9