#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <stack>

using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if (start == end)    // 노드가 리프 노드인 경우
        return tree[node] = arr[start];    // 배열의 그 원소를 가져야 함

    int mid = (start + end) / 2;
//    cout << start << " " << mid << " " << end << endl;

    // 구간 합을 구하는 경우
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);

    // 구간의 최솟값을 구하는 경우도 비슷하게 해줄 수 있다.
    // return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우,
    // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다.
    if (left > end || right < start) return 0;

    // case 2: [start, end]가 [left, right]에 포함
    if (left <= start && end <= right) return tree[node];

    // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}


void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;    // case 2
    tree[node] = tree[node] + diff;    // case 1

    // 리프 노드가 아닌 경우 자식도 변경해줘야 하기 때문에,
    // 리프 노드인지 검사를 하고 아래 자식 노드를 갱신해준다.
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

// 1000000000000000000
// 1초: 1억번
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int len, updateLen, sumLen;
    cin >> len >> updateLen >> sumLen;

    vector<long long> vec;
    for (int i = 0; i < len; ++i) {
        long long n;
        cin >> n;
        vec.push_back(n);
    }


    vector<long long> segTree(4 * len);

    init(vec, segTree, 1, 0, len - 1);

//    for (long long n: segTree) {
//        cout << n << " ";
//    }
//    cout << endl;


    for (int i = 0; i < updateLen + sumLen; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            // 업데이트
            long long val = c;
            int index = b - 1;
            long long diff = val - vec[index];
            vec[index] = val;
            update(segTree, 1, 0, len - 1, index, diff);

        } else if (a == 2) {
            int left = b - 1;
            int right = c - 1;
            long long plus = sum(segTree, 1, 0, len - 1, left, right);

            cout << plus << endl;
        }
    }


}
// 5
// 1 2 3 4 5
