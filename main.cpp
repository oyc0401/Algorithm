#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <stack>

using namespace std;

class Square {
public:
    Square(int e = 0, int idx = 0) {
        this->e = e;
        this->index = idx;
    }

    int e;
    int index;
};

//template<typename Square>
class SegTree {
public:

    SegTree(vector<Square> &arr) {
        len = arr.size();
        tree = vector<Square>(4 * len);
        init(arr, 1, 0, len - 1);
    }


    Square init(vector<Square> &arr, int node, int start, int end) {
        if (start == end)    // 노드가 리프 노드인 경우
            return tree[node] = arr[start];    // 배열의 그 원소를 가져야 함

        int mid = (start + end) / 2;
//    cout << start << " " << mid << " " << end << endl;

        // 구간 합을 구하는 경우
//    return tree[node] = mininit(arr, tree, node * 2, start, mid) + mininit(arr, tree, node * 2 + 1, mid + 1, end);

        // 구간의 최솟값을 구하는 경우도 비슷하게 해줄 수 있다.

        Square a = init(arr, node * 2, start, mid);
        Square b = init(arr, node * 2 + 1, mid + 1, end);
        if (a.e > b.e) {
            return tree[node] = a;
        } else {
            return tree[node] = b;
        }
    }

    Square sum(int node, int start, int end, int left, int right) {
        // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우,
        // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다.
        if (left > end || right < start) return Square(0, -1);

        // case 2: [start, end]가 [left, right]에 포함
        if (left <= start && end <= right) return tree[node];

        // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
        int mid = (start + end) / 2;

        Square a = sum(node * 2, start, mid, left, right);
        Square b = sum(node * 2 + 1, mid + 1, end, left, right);
        if (a.e > b.e) {
            return a;
        } else {
            return b;
        }

    }

//    Square update(int node, int start, int end, int index, Square val) {
//        if (index > end || index < start) return tree[node];
//        if (start == end) return tree[node] = val;
//        int mid = start + (end - start) / 2;
//
//        Square a = update(node * 2, start, mid, index, val);
//        Square b = update(node * 2 + 1, mid + 1, end, index, val);
//        if (a.e < b.e) {
//            return tree[node] = a;
//        } else {
//            return tree[node] = b;
//        }
//
//    }


    void print() {
        for (Square e: tree) {
            cout << e.e << " ";
        }
        cout << endl;
    }


private:
    int len;
    vector<Square> tree;
};


// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int len, width;
    int maxSize = -1;
    cin >> len >> width;

    vector<Square> vec;
    for (int i = 0; i < len; ++i) {
        int n;
        cin >> n;
        Square square = Square();
        square.e = n;
        square.index = i;
        vec.push_back(square);
    }


    SegTree segTree(vec);

//    segTree.print();

    for (int i = 0; i < len - width; ++i) {

        int start = i;
        int end = i + 2 * (width - 1);
//        cout << start << " " << end << endl;
        Square s = segTree.sum(1, 0, len - 1, start, end);
        cout << s.e << " ";
    }

//    Square s = segTree.sum(1, 0, len - 1, start, end);


//    cout << maxSize << endl;
}

//8
//1 2 3 4 5 6 7 8