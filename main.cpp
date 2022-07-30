#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


vector<int> node[100001];
int depth[100001];


void setDep(int n) {
    for (int arrow: node[n]) {

        if (depth[arrow] > depth[n] + 1) {
            depth[arrow] = depth[n] + 1;
            setDep(arrow);
        }

    }
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int index;
    cin >> index;




    /// 입력
    for (int i = 0; i < index - 1; ++i) {
        int po;
        int a;

        cin >> po >> a;

        node[po].push_back(a);
        node[a].push_back(po);
    }

    for (int &n: depth) {
        n = 100001;
    }
    depth[1] = 0;

    setDep(1);


//    for (int i = 1; i <= index; ++i) {
//        cout << depth[i] << " ";
//    }
//cout<<endl;


    for (int i = 2; i <= index; ++i) {
        int small = 100001;
        int nodes;
        for (int n: node[i]) {
            if (depth[n] < small) {
                small = depth[n];
                nodes = n;
            }
        }
        cout << nodes << "\n";
    }
}


