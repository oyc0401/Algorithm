#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <stack>

using namespace std;

class Node {
public:

    int a, b, w;

    void print() {
        cout << a << " " << b << " " << w << endl;
    }

    bool operator<(const Node &loc2) const {
        return w > loc2.w;
    }
};


bool compare(Node x, Node y) {
    return x.w < y.w;
}



// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, edgeCount;
    vector<vector<pair<int, int>>> nodeArr;
    long long sum = 0;

    cin >> T >> edgeCount;

    int visited[T];
    for (int i = 0; i < T; ++i) {
        visited[i] = false;
    }

    nodeArr = vector<vector<pair<int, int>>>(T);


//    for (int i = 0; i < T; ++i) {
//        for (int j = 0; j < T; ++j) {
//            arr[i][j] = INF;
//        }
//        cout << endl;
//    }



//    cout << "노드 출력:" << endl;
//    for (int i = 0; i < count; ++i) {
//        for (int j = 0; j < count; ++j) {
//            cout << node[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    vector<Node> vec;

    for (int i = 0; i < edgeCount; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
//        node[a][b] = w;
//        node[b][a] = w;
        Node node = Node();
        node.a = a;
        node.b = b;
        node.w = w;
        vec.push_back(node);
        nodeArr[node.a].push_back(make_pair(node.b, node.w));
        nodeArr[node.b].push_back(make_pair(node.a, node.w));
    }


    std::sort(vec.begin(), vec.end(), compare);

//    for (int i = 0; i < nodeCount; ++i) {
//        vec[i].print();
//    }


    int minNode = vec[0].a;
    visited[minNode] = true;


    priority_queue<Node> que;
    for (auto pa: nodeArr[minNode]) {
        Node no = Node();
        no.a = minNode;
        no.b = pa.first;
        no.w = pa.second;
        que.push(no);
//        cout << "push: ";
//        no.print();
    }
    while (!que.empty()) {
        if (visited[que.top().b] == false) {
//            Node n = que.top();
//            n.print();
            sum += que.top().w;
            visited[que.top().b] = true;

            int topB = que.top().b;
            que.pop();

            for (auto pa: nodeArr[topB]) {
                if (visited[pa.first] == false) {
                    Node no = Node();
                    no.a = topB;
                    no.b = pa.first;
                    no.w = pa.second;
                    que.push(no);
//                    cout << "push: ";
//                    no.print();
//                    cout << "top: " << que.top().a << " " << que.top().b << " " << que.top().w<<endl;
                }

            }
        } else {
//            cout << "거절: ";
//            Node n = que.top();
//            n.print();
            que.pop();
        }

    }
    cout << sum;

    //5 5
    //1 4 3
    //2 3 3
    //4 3 5
    //2 1 6
    //4 5 9

}

//3 2
//1 2 1
//2 3 2


