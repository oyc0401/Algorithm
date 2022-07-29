#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


vector<pair<int, int>> node[100001];
bool check[100001];

pair<int, int> parTree(int position, int lenght) {
    vector<pair<int, int>> &vec = node[position];


    pair<int, int> target = make_pair(position, lenght);
    for (pair<int, int> pa: vec) {

        if (!check[pa.first]) {
            ///cout << "po: " << position << ", l: " << pa.first << " " << lenght +pa.second << endl;
            check[pa.first] = true;
            pair<int, int> pai = parTree(pa.first, lenght + pa.second);

            // 더 큰거 저장
            if (target.second <= pai.second) {
                target = pai;
            }
        }
    }

    return target;

}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int index;
    cin >> index;



    /// 입력
    for (int i = 1; i <= index; ++i) {
        int po;
        int a;
        int b;
        cin >> po >> a;
        while (a != -1) {
            cin >> b;
            pair<int, int> pa = make_pair(a, b);
            node[po].push_back(pa);

            cin >> a;
        }
    }

    int start=1;
    check[start] = true;
    pair<int, int> pa = parTree(start, 0);

    ///cout << pa.first << ", " << pa.second << endl;

    // 두번째
    start = pa.first;

    for (bool &b: check) {
        b = false;
    }

    check[start] = true;
    pair<int, int> value = parTree(start, 0);

    ///cout << value.first << ", " << value.second << endl;


    cout<<value.second;


}


