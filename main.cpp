
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

    int num;
    cin >> num;

    string *arr = new string[num];


    for (int i = 0; i < num; ++i) {
        cin >> arr[i];
    }


    queue<pair<int, int>> que;

    vector<int> vec;

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if (arr[i][j] == '1') {
                int sum = 0;

                que.push(make_pair(i, j));
                arr[i][j] = '0';
                sum++;

                while (!que.empty()) {
                    int a = que.front().first;
                    int b = que.front().second;
                    for (int k = 0; k < 4; ++k) {
                        int nx = a + dx[k];
                        int ny = b + dy[k];
                        if (0 <= nx && 0 <= ny && nx < num && ny < num
                            && arr[nx][ny] == '1') {
                            que.push(make_pair(nx, ny));
                            arr[nx][ny] = '0';
                            sum++;
                        }
                    }
                    que.pop();

                }
                vec.push_back(sum);
            }
        }
    }

    std::sort(vec.begin(), vec.end());
    cout << vec.size() << '\n';
    for (int n: vec) {
        cout << n << '\n';
    }


    return 0;
}


