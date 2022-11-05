
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

    int dx[8] = {1, -1, 0, 0,1,1,-1,-1};
    int dy[8] = {0, 0, 1, -1,1,-1,1,-1};

    int x, y;
    cin >> x >> y;

    while (x != 0 || y != 0) {


        int **arr = new int *[y];
        for (int i = 0; i < y; ++i) {
            arr[i] = new int[x];
        }

        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                cin >> arr[i][j];
            }
        }

//    /// print
//    for (int i = 0; i < y; ++i) {
//        for (int j = 0; j < x; ++j) {
//            cout << arr[i][j] << " ";
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//    /// print


        // bool visted[9][9];
        queue<pair<int, int>> que;


        int sum = 0;
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                if (arr[i][j] == 1) {
                    sum++;
                    //cout<<": "<<j<<", "<<i<<endl;

                    que.push(make_pair(j, i));
                    arr[i][j] = 0;
                    while (!que.empty()) {
                        int a = que.front().first;
                        int b = que.front().second;
                        for (int k = 0; k < 8; ++k) {
                            int nx = a + dx[k];
                            int ny = b + dy[k];
                           // cout<<"??: "<<a<<", "<<b<<endl;
                            //cout<<"n: "<<nx<<", "<<ny<<endl;
                            if (0 <= nx && 0 <= ny && nx < x && ny < y
                                && arr[ny][nx] == 1) {

                                que.push(make_pair(nx, ny));
                                arr[ny][nx] = 0;
                            }
                        }
                        que.pop();

                    }

                }
            }
        }

        cout << sum<<'\n';
        cin >> x >> y;
    }


    return 0;
}


