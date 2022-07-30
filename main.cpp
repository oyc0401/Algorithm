#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

int nodeNum, edgeNum, start;

vector<pair<int, int>> arr[20001]; // arr[1]를 for 돌리면 1번에서 갈 수 있는 (weight, node) 나온다.
int dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> nodeNum >> edgeNum >> start;



    /// 입력
    for (int i = 1; i <= edgeNum; ++i) {
        int po, a, w;
        cin >> po >> a >> w;

        arr[po].push_back(make_pair(w, a));
    }

    int INF = 1000000;
    // 거리 배열 무한으로 초기화
    for (int i = 0; i < 20001; ++i) {
        dist[i] = INF;
    }

    que.push(make_pair(0,start));
    dist[start]=0;

    while (!que.empty()) {
        pair<int, int> Qpair = que.top();
       /// cout << Qpair.first << ", " << Qpair.second << endl;

        // 이번 노드 거리가 기존 거리보다 작거나 같다면 경로 찾기
        if (dist[Qpair.second] >= Qpair.first) {
            ///cout<<"새로운거 찾음: "<<Qpair.second<<endl;

            // 큐에 있는 노드에서 길 수 있는 노드와 거리를 탐색
            for (pair<int, int> pa: arr[Qpair.second]) {
                ///cout << Qpair.second << "번 경로: " << pa.first << ", " << pa.second << endl;
                int allWeight = pa.first + Qpair.first;
                int node = pa.second;

                // 새로 얻은 거리가 기존 거리보다 작으면
                if (allWeight < dist[node]) {
                    // 거리를 다시 만들고
                    dist[node] = allWeight;
                    // 큐에 넣기
                    ///cout<<"큐 삽입: "<<allWeight<<", "<<node<<endl;
                    que.push(make_pair(allWeight, node));
                }
            }

        }


        que.pop();

    }






    /// 출력
    for (int i = 1; i <= nodeNum; ++i) {
        int val = dist[i];

        if (val == INF) {
            cout << "INF" << endl;
        } else {
            cout << val << endl;
        }

    }


}

//6 9
//1
//5 1 1
//1 2 2
//1 3 3
//2 3 4
//2 4 5
//3 4 6
//1 6 1
//6 3 1
//4 1 1
