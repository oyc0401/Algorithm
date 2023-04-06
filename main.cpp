#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <stack>

using namespace std;

//1,000,000,000
class Node {
public:
    int x, y, z;
    int id;

    void print() {
        cout << id << " (" << x << ", " << y << ", " << z << ")" << endl;


    }
};

class Node2 {
public:
    Node *node;
};


class Edge {
public:
    int node[2];
    int distance;

    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }

    bool operator<(Edge &edge) {
        return this->distance < edge.distance;
    }


};

bool compareE(Edge &edge1, Edge &edge2) {
    return edge1.distance < edge2.distance;
}

bool compareX(Node2 a, Node2 b) {
    return a.node->x < b.node->x;
}

bool compareY(Node2 a, Node2 b) {
    return a.node->y < b.node->y;
}

bool compareZ(Node2 a, Node2 b) {
    return a.node->z < b.node->z;
}


int getParent(int set[], int x) {
    if (set[x] == x) return x;
    return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if (a < b) set[b] = a;
    else set[a] = b;
}

int find(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if (a == b) return 1;
    else return 0;
}


// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<Node2> xArr;
    vector<Node2> yArr;
    vector<Node2> zArr;

    long long sum = 0;

    int nodeCnt;
    cin >> nodeCnt;

    int visited[nodeCnt];
    for (int i = 0; i < nodeCnt; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < nodeCnt; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        Node *node = new Node();
        node->x = x;
        node->y = y;
        node->z = z;
        node->id = i;

        Node2 xEdge = Node2();
        Node2 yEdge = Node2();
        Node2 zEdge = Node2();

        xEdge.node = node;
        yEdge.node = node;
        zEdge.node = node;

        xArr.push_back(xEdge);
        yArr.push_back(yEdge);
        zArr.push_back(zEdge);
    }


    std::sort(xArr.begin(), xArr.end(), compareX);
    std::sort(yArr.begin(), yArr.end(), compareY);
    std::sort(zArr.begin(), zArr.end(), compareZ);
//
//    cout << "\nx정렬:\n";
//    for (int i = 0; i < nodeCnt; ++i) {
//        xArr[i].node->print();
//    }
//    cout << "\ny정렬:\n";
//    for (int i = 0; i < nodeCnt; ++i) {
//        yArr[i].node->print();
//    }
//    cout << "\nz정렬:\n";
//    for (int i = 0; i < nodeCnt; ++i) {
//        zArr[i].node->print();
//    }
//    cout << '\n';


    vector<Edge> vec;
    for (int i = 0; i < nodeCnt - 1; ++i) {
        int a = xArr[i].node->x;
        int b = xArr[i + 1].node->x;
        int aId = xArr[i].node->id;
        int bId = xArr[i + 1].node->id;

        int dist = abs(a - b);

        vec.push_back(Edge(aId, bId, dist));
    }

    for (int i = 0; i < nodeCnt - 1; ++i) {
        int a = yArr[i].node->y;
        int b = yArr[i + 1].node->y;
        int aId = yArr[i].node->id;
        int bId = yArr[i + 1].node->id;




        int dist = abs(a - b);

        vec.push_back(Edge(aId, bId, dist));
    }

    for (int i = 0; i < nodeCnt - 1; ++i) {
        int a = zArr[i].node->z;
        int b = zArr[i + 1].node->z;
        int aId = zArr[i].node->id;
        int bId = zArr[i + 1].node->id;

        int dist = abs(a - b);

        vec.push_back(Edge(aId, bId, dist));
    }

    sort(vec.begin(), vec.end(), compareE);
//    for (Edge e: vec) {
//        cout << e.node[0] << " " << e.node[1]<<" "<<e.distance << endl;
//    }





    int set[nodeCnt];
    for (int i = 0; i < nodeCnt; ++i) {
        set[i] = i;
    }

//    cout << "!\n";
    for (int i = 0; i < vec.size(); ++i) {
        if (!find(set, vec[i].node[0] , vec[i].node[1] )) {
            sum += vec[i].distance;
//            cout << vec[i].node[0] << " " << vec[i].node[1]<<" "<<vec[i].distance << endl;
            unionParent(set, vec[i].node[0] , vec[i].node[1] );
        }
    }

    cout << sum;
}

//3 2
//1 2 1
//2 3 2


