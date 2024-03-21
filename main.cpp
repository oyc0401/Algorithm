#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <stack>

using namespace std;

class SegTree {
public:

    SegTree(vector<int> &arr) {
        len = arr.size();

//        int h = (int) ceil(log2(len));
//        int tree_size = (1 << (h + 1));
        int tree_size = 4 * len;

        tree = vector<long long>(tree_size);
        init(arr, 1, 0, len - 1);
    }


    long long init(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            long long ll = arr[start];
            return tree[node] = ll;
        }

        int mid = (start + end) / 2;

        // 구간 합을 구하는 경우
        long long a = init(arr, node * 2, start, mid);
        long long b = init(arr, node * 2 + 1, mid + 1, end);
//        if (a <= b) {
//            return b;
//        } else {
//            return a;
//        }
        return tree[node] = a + b;
    }

    long long sum(int node, int start, int end, int left, int right) {
        // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우,
        // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다.
        if (left > end || right < start) return 0;

        // case 2: [start, end]가 [left, right]에 포함
        if (left <= start && end <= right) return tree[node];

        // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
        int mid = (start + end) / 2;

        long long a = sum(node * 2, start, mid, left, right);
        long long b = sum(node * 2 + 1, mid + 1, end, left, right);
//        if (a <= b) {
//            return b;
//        } else {
//            return a;
//        }

        return a + b;
    }

    long long update(int node, int start, int end, int index, int val) {
        if (index > end || index < start) return tree[node];
        if (start == end) return tree[node] = val;
        int mid = start + (end - start) / 2;

        long long a = update(node * 2, start, mid, index, val);
        long long b = update(node * 2 + 1, mid + 1, end, index, val);

//        if (a <= b) {
//            return tree[node] = b;
//        } else {
//            return tree[node] = a;
//        }

        return tree[node] = a + b;

    }

    long long query(int node, int target, int leftCount, int start, int end) {
        tree[node]--;

        if (start == end) return start;
        int mid = start + (end - start) / 2;

        if (target <= tree[node * 2] + leftCount) {
            return query(node * 2, target, leftCount, start, mid);
        } else {
            return query(node * 2 + 1, target, tree[node * 2] + leftCount, mid + 1, end);
        }


//        if (a <= b) {
//            return tree[node] = b;
//        } else {
//            return tree[node] = a;
//        }

//        return tree[node] = a + b;

    }


    void print() {
        for (int i = 0; i < 50; ++i) {
            cout << tree[i] << " ";
        }
//        for (long long e: tree) {
//            cout << e << " ";
//        }
        cout << endl;
    }


private:
    int len;
    vector<long long> tree;
};



// 1000000000000000000
// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    int length = 2'000'000;
    vector<int> vec(length);
    SegTree segTree(vec);

    for (int i = 0; i < count; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            cin >> b;
            b--;
            vec[b]++;
            segTree.update(1, 0, length - 1, b, vec[b]);
        }
        if (a == 2) {
            int b;
            cin >> b;
            int idx = segTree.query(1, b, 0, 0, length - 1);
            vec[idx]--;
            cout << idx + 1 << '\n';
        }
    }

}


