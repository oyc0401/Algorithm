#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

class arrow {
public:
    arrow(int node, int target, int weight) : node(node), target(target), weight(weight) {

    }

    string to_string() {
        string a = "(" + std::to_string(node) + ", " + std::to_string(target)
                   + ", " + std::to_string(weight) + ")";
        return a;
    }

    int node, target, weight;
private:

};

int dist[501];
vector<arrow> vec;
const int INF = 10000000;
int nodeNum, roadNum, wormNum;

bool bell() {
    dist[1] = 0;
    for (int i = 0; i < nodeNum; ++i) {
        for (arrow arr: vec) {
            if ( dist[arr.target] > dist[arr.node] + arr.weight) {
                //cout<<arr.to_string()<<endl;
                dist[arr.target] = dist[arr.node] + arr.weight;
                if (i == nodeNum - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

void going() {

    vec.clear();

    // 거리 초기화
    for (int i = 0; i < 501; ++i) {
        dist[i] = INF;
    }

    cin >> nodeNum >> roadNum >> wormNum;

    for (int i = 0; i < roadNum; ++i) {
        int node, target, weight;
        cin >> node >> target >> weight;
        vec.push_back(arrow(node, target, weight));
        vec.push_back(arrow(target, node, weight));
    }
    for (int i = 0; i < wormNum; ++i) {
        int node, target, weight;
        cin >> node >> target >> weight;
        vec.push_back(arrow(node, target, -weight));

    }

//    /// 간선 프린트
//    for (int i = 0; i < vec.size(); ++i) {
//        cout << vec[i].to_string() << ", ";
//    }
//    cout << endl;
//    /// 간선 프린트


    bool isCycle = bell();


    if (isCycle) {
        // 음수 순환 발생
        cout << "YES";
    } else {
        // 음수 순환 안발생
        cout << "NO";
    }
    cout << endl;

//    /// 거리 프린트
//    for (int i = 1; i <= nodeNum; ++i) {
//        cout << dist[i] << ", ";
//    }
//    /// 거리 프린트
}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ind;
    cin>>ind;

    for (int i = 0; i < ind; ++i) {
        going();
    }

}
//3 3 1
//1 2 2
//1 3 4
//2 3 1
//3 1 3

//3 2 1
//1 2 3
//2 3 4
//3 1 8
