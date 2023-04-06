#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <stack>

using namespace std;

class Obj {
    int e;
    int index;
};

template<typename T>
class MinSegTree {
public:

    MinSegTree(vector<T> &arr) {
        int len = arr.size();
        tree = vector<T>(4 * len);
        init(arr, 1, 0, len - 1);
    }


    T init(vector<T> &arr, int node, int start, int end) {
        if (start == end)    // 노드가 리프 노드인 경우
            return tree[node] = arr[start];    // 배열의 그 원소를 가져야 함

        int mid = (start + end) / 2;
//    cout << start << " " << mid << " " << end << endl;

        // 구간 합을 구하는 경우
//    return tree[node] = mininit(arr, tree, node * 2, start, mid) + mininit(arr, tree, node * 2 + 1, mid + 1, end);

        // 구간의 최솟값을 구하는 경우도 비슷하게 해줄 수 있다.
        return tree[node] = min(init(arr, node * 2, start, mid), init(arr, node * 2 + 1, mid + 1, end));
    }

    T sum(int node, int start, int end, int left, int right) {
        // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우,
        // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다.
        if (left > end || right < start) return 1000000001;

        // case 2: [start, end]가 [left, right]에 포함
        if (left <= start && end <= right) return tree[node];

        // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
        int mid = (start + end) / 2;
        return min(sum(node * 2, start, mid, left, right), sum(node * 2 + 1, mid + 1, end, left, right));
    }

    T update(int node, int start, int end, int index, T val) {
        if (index > end || index < start) return tree[node];
        if (start == end) return tree[node] = val;
        int mid = start + (end - start) / 2;
        return tree[node] = min(update(node * 2, start, mid, index, val),
                                update(node * 2 + 1, mid + 1, end, index, val));

    }


private:
    vector<T> tree;
};


// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len, sumLen;
    cin >> len;

    vector<long long> vec;
    for (int i = 0; i < len; ++i) {
        int n;
        cin >> n;
        vec.push_back(n);
    }
    cin >> sumLen;

    MinSegTree<long long> segTree(vec);

    for (int i = 0; i < sumLen; ++i) {
        int M, a, b;
        cin >> M >> a >> b;
        if (M == 1) {
            // 업데이트
            long long val = b;
            int index = a - 1;
            vec[index] = val;
            segTree.update(1, 0, len - 1, index, val);
        } else {
            int left = a - 1;
            int right = b - 1;
            long long minS = segTree.sum(1, 0, len - 1, left, right);

            cout << minS << '\n';
        }

    }


}
