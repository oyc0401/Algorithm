
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int x, y;
    cin >> x;
    y = x;


    int **arr = new int *[y];
    for (int i = 0; i < y; ++i) {
        arr[i] = new int[x];
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            cin >> arr[i][j];
        }
    }


    vector<int> vec;
    for (int blank = 0; blank <= 100; ++blank) {

        bool visted[101][101];
        for (int i = 0; i < 101; ++i) {
            for (int j = 0; j < 101; ++j) {
                visted[i][j] = false;
            }
        }

        queue<pair<int, int>> que;


        int sum = 0;
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                if (arr[i][j] > blank&&!visted[i][j]) {

                    //  cout<<": "<<j<<", "<<i<<endl;

                    que.push(make_pair(j, i));
                    visted[i][j] = true;
                    sum++;

                    // 인접한거 제거
                    while (!que.empty()) {
                        int a = que.front().first;
                        int b = que.front().second;
                        for (int k = 0; k < 4; ++k) {
                            int nx = a + dx[k];
                            int ny = b + dy[k];
                            // cout<<"??: "<<a<<", "<<b<<endl;
                            //cout<<"n: "<<nx<<", "<<ny<<endl;
                            if (0 <= nx && 0 <= ny && nx < x && ny < y
                                && arr[ny][nx] > blank && !visted[ny][nx]) {

                                //cout<<"?";
                                que.push(make_pair(nx, ny));
                                visted[ny][nx] = true;
                            }
                        }
                        que.pop();

                    }

                }
            }
        }

        //cout << sum << '\n';
        vec.push_back(sum);


    }

    int max = vec[0];
    for (int n: vec) {
        if (max < n) {
            max = n;
        }

    }

    cout << max;


//        /// print
//    for (int i = 0; i < y; ++i) {
//        for (int j = 0; j < x; ++j) {
//            cout << arr[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//    /// print

    return 0;
}


