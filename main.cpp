#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <stack>


using namespace std;

int node, ind, start;
vector<int> edge[1001];

bool DFS_check[1001];
bool BFS_check[1001];


//stack<int> printStack;
queue<int> printDFS;
queue<int> printQue;

void DFS(int num) {

    /// cout << num << " ";
    DFS_check[num] = true;

    for (int n: edge[num]) {
        if (!DFS_check[n]) {
            printDFS.push(n);
            DFS(n);
        }
    }


}

void BFS(int num) {
    queue<int> que;

    // 처음 큐 넣기
    que.push(num);

    // 큐 순환
    while (!que.empty()) {
        /// cout<<que.front()<<" ";

        if (!BFS_check[que.front()]) {
            BFS_check[que.front()] = true;
            printQue.push(que.front());

            for (int n: edge[que.front()]) {
                que.push(n);
            }
        }

        que.pop();
    }


}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> node >> ind >> start;

    for (int i = 0; i < ind; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    // 정렬
    for (vector<int> &v: edge) {
        std::sort(v.begin(), v.end());
    }


    printDFS.push(start);
    DFS(start);
    while (!printDFS.empty()) {
        cout << printDFS.front() << " ";
        printDFS.pop();
    }

    cout<<"\n";

    BFS(start);
    while (!printQue.empty()) {
        cout << printQue.front() << " ";
        printQue.pop();
    }

    return 0;
}


