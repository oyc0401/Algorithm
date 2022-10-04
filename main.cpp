
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

    int num;
    cin >> num;

    string *arr = new string[num];


    for (int i = 0; i < num; ++i) {
        cin >> arr[i];
    }

//    ///print
//    for (int i = 0; i < num; ++i) {
//        cout << arr[i];
//        cout << endl;
//    }

    queue<pair<int, int>> que;

    vector<int> vec;

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if (arr[i][j] == '1') {
                int sum = 0;

                que.push(make_pair(i, j));
                arr[i][j]='0';
                sum++;
                while (!que.empty()) {

                    int x = que.front().first;
                    int y = que.front().second;
                    if (0 < x && arr[x - 1][y] == '1') {
                        que.push(make_pair(x - 1, y));
                        arr[x - 1][y] = '0';
                        sum++;
                    }
                    if (x < num - 1 && arr[x + 1][y] == '1') {
                        que.push(make_pair(x + 1, y));
                        arr[x + 1][y] = '0';
                        sum++;
                    }
                    if (0 < y && arr[x][y - 1] == '1') {
                        que.push(make_pair(x, y - 1));
                        arr[x][y - 1] = '0';
                        sum++;
                    }
                    if (y < num - 1 && arr[x][y + 1] == '1') {
                        que.push(make_pair(x, y + 1));
                        arr[x][y + 1] = '0';
                        sum++;
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


