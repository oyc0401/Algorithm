#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

class locate {
public:

    locate(int y, int x, bool canBreak, int dist) : x(x), y(y), canBreak(canBreak), dist(dist) {

    }

    int x, y, dist;
    bool canBreak;
};

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   /// cout.tie(NULL);

    int y, x;
    cin >> y >> x;


    bool **went = new bool *[y];
    for (int i = 0; i < y; ++i) {
        went[i] = new bool[x];
    }

    bool **breakWent = new bool *[y];
    for (int i = 0; i < y; ++i) {
        breakWent[i] = new bool[x];
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            went[i][j] = false;
            breakWent[i][j] = false;
        }
    }


    string *arr = new string[y];
//string arr[1001];

    for (int i = 0; i < y; ++i) {
        string st;
        cin >> st;
        /////cout<<st<<endl;
        arr[i] = st;
    }


    queue<locate> que;
    que.push(locate(0, 0, true, 1));
    //arr[0][0] = '2';
    went[0][0] = true;
    breakWent[0][0] = true;

    /// print
    for (int i = 0; i < y; ++i) {
        for (int k = 0; k < x; ++k) {
            if (went[i][k]) {
               /// cout << '2' << ' ';
            } else {
               /// cout << arr[i][k] << ' ';
            }
        }

       /// cout << "| ";

        for (int k = 0; k < x; ++k) {
            if (breakWent[i][k]) {
               /// cout << '2' << ' ';
            } else {
               /// cout << arr[i][k] << ' ';
            }
        }

       /// cout << endl;
    }
   /// cout << endl;


    while (!que.empty()) {
        locate loca = que.front();


       /// cout << loca.x << ", " << loca.y << ", " << loca.dist <<", "<<loca.canBreak<< endl;

        /// 도착
        if (loca.x == x - 1 && loca.y == y - 1) {
            cout << loca.dist;
            return 0;
        }

        /// 위쪽
        if (loca.canBreak) {
            if (loca.y > 0 && arr[loca.y - 1][loca.x] == '0' && !went[loca.y - 1][loca.x]) {
               /// cout << "위쪽" << endl;
                que.push(locate(loca.y - 1, loca.x, loca.canBreak, loca.dist + 1));
                went[loca.y - 1][loca.x] = true;
                breakWent[loca.y - 1][loca.x] = true;
            }
        } else {
            if (loca.y > 0 && arr[loca.y - 1][loca.x] == '0' && !breakWent[loca.y - 1][loca.x]) {
               /// cout << "위쪽" << endl;
                que.push(locate(loca.y - 1, loca.x, loca.canBreak, loca.dist + 1));
                breakWent[loca.y - 1][loca.x] = true;
            }
        }

        /// 위쪽벽
        if (loca.y - 1 > 0 && arr[loca.y - 1][loca.x] == '1' && arr[loca.y - 2][loca.x] == '0'
            && loca.canBreak && !breakWent[loca.y - 2][loca.x]) {
           /// cout << "위쪽벽" << endl;
            que.push(locate(loca.y - 2, loca.x, false, loca.dist + 2));
            breakWent[loca.y - 2][loca.x] = true;
        }

        /// 아래쪽
        if (loca.canBreak) {
            if (loca.y < y - 1 && arr[loca.y + 1][loca.x] == '0' && !went[loca.y + 1][loca.x]) {
               /// cout << "아래쪽" << endl;
                que.push(locate(loca.y + 1, loca.x, loca.canBreak, loca.dist + 1));
                went[loca.y + 1][loca.x] = true;
                breakWent[loca.y + 1][loca.x] = true;
            }
        } else {
            if (loca.y < y - 1 && arr[loca.y + 1][loca.x] == '0' && !breakWent[loca.y + 1][loca.x]) {
               /// cout << "아래쪽" << endl;
                que.push(locate(loca.y + 1, loca.x, loca.canBreak, loca.dist + 1));
                breakWent[loca.y + 1][loca.x] = true;
            }
        }


        /// 아래쪽벽
        if (loca.y + 1 < y - 1 && arr[loca.y + 1][loca.x] == '1' && arr[loca.y + 2][loca.x] == '0'
            && loca.canBreak && !breakWent[loca.y + 2][loca.x]) {
           /// cout << "아래쪽벽" << endl;
            que.push(locate(loca.y + 2, loca.x, false, loca.dist + 2));
            breakWent[loca.y + 2][loca.x] = true;
        }

        /// 왼쪽
        if (loca.canBreak) {
            if (loca.x > 0 && arr[loca.y][loca.x - 1] == '0' && !went[loca.y][loca.x - 1]) {
               /// cout << "왼쪽" << endl;
                que.push(locate(loca.y, loca.x - 1, loca.canBreak, loca.dist + 1));
                went[loca.y][loca.x - 1] = true;
                breakWent[loca.y][loca.x - 1] = true;
            }

        } else {
            if (loca.x > 0 && arr[loca.y][loca.x - 1] == '0' && !breakWent[loca.y][loca.x - 1]) {
               /// cout << "왼쪽" << endl;
                que.push(locate(loca.y, loca.x - 1, loca.canBreak, loca.dist + 1));
                breakWent[loca.y][loca.x - 1] = true;
            }

        }

        /// 왼쪽벽
        if (loca.x - 1 > 0 && arr[loca.y][loca.x - 1] == '1' && arr[loca.y][loca.x - 2] == '0'
            && loca.canBreak && !breakWent[loca.y][loca.x - 2]) {
           /// cout << "왼쪽벽" << endl;
            que.push(locate(loca.y, loca.x - 2, false, loca.dist + 2));
            breakWent[loca.y][loca.x - 2] = true;
        }


        /// 오른쪽
        if (loca.canBreak) {
            if (loca.x < x - 1 && arr[loca.y][loca.x + 1] == '0' && !went[loca.y][loca.x + 1]) {
               /// cout << "오른쪽" << endl;
                que.push(locate(loca.y, loca.x + 1, loca.canBreak, loca.dist + 1));
                went[loca.y][loca.x + 1] = true;
                breakWent[loca.y][loca.x + 1] = true;
            }
        } else {
            if (loca.x < x - 1 && arr[loca.y][loca.x + 1] == '0' && !breakWent[loca.y][loca.x + 1]) {
               /// cout << "오른쪽" << endl;
                que.push(locate(loca.y, loca.x + 1, loca.canBreak, loca.dist + 1));
                breakWent[loca.y][loca.x + 1] = true;
            }
        }


        /// 오른쪽벽
        if (loca.x + 1 < x - 1 && arr[loca.y][loca.x + 1] == '1' && arr[loca.y][loca.x + 2] == '0'
            && loca.canBreak && !breakWent[loca.y][loca.x + 2]) {
           /// cout << "오른쪽벽" << endl;
            que.push(locate(loca.y, loca.x + 2, false, loca.dist + 2));
            breakWent[loca.y][loca.x + 2] = true;
        }

        /// print
        for (int i = 0; i < y; ++i) {
            for (int k = 0; k < x; ++k) {
                if (went[i][k]) {
                   /// cout << '2' << ' ';
                } else {
                   /// cout << arr[i][k] << ' ';
                }
            }

           /// cout << "| ";

            for (int k = 0; k < x; ++k) {
                if (breakWent[i][k]) {
                   /// cout << '2' << ' ';
                } else {
                   /// cout << arr[i][k] << ' ';
                }
            }

           /// cout << endl;
        }
       /// cout << endl;

        que.pop();

    }


    cout << -1;

}

//6 4
//0000
//1110
//1000
//0000
//1111
//0000

