
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

class Point {
public:
    int x;
    int y;
    int h;
};

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, h;
    cin >> x >> y >> h;


    int ***arr = new int **[h];
    for (int i = 0; i < h; i++) {
        arr[i] = new int *[y];
        for (int j = 0; j < y; ++j) {
            arr[i][j] = new int [x];
        }
    }



    queue<Point> que;
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                int a;
                cin >> a;
                arr[k][i][j] = a;
                if (a == 1) {
                    Point point;
                    point.h = k;
                    point.y = i;
                    point.x = j;
                    que.push(point);
                }
            }
        }
    }


    int sum = 0;

    while (!que.empty()) {
        int size = que.size();
        bool isChanged = false;

        for (int i = 0; i < size; ++i) {
            Point pa = que.front();
            que.pop();
            const int X = pa.x;
            const int Y = pa.y;
            const int H = pa.h;

            // cout<<"i: "<<i<<", x: "<<X<<", y: "<<Y<<", sum: "<<sum<<endl;
            //cout << "sum: " << sum << ", x: " << X << ", y: " << Y << endl;
            // 왼쪽
            if (X > 0 && arr[H][Y][X - 1] == 0) {
                arr[H][Y][X - 1] = 1;
                Point tuple;
                tuple.h = H;
                tuple.x = X - 1;
                tuple.y = Y;

                que.push(tuple);
                isChanged = true;
            }
            // 오른쪽
            if (X < x - 1 && arr[H][Y][X + 1] == 0) {
                arr[H][Y][X + 1] = 1;
                Point tuple;
                tuple.h = H;
                tuple.x = X + 1;
                tuple.y = Y;
                que.push(tuple);
                isChanged = true;
            }
            // 위쪽
            if (Y > 0 && arr[H][Y - 1][X] == 0) {
                arr[H][Y - 1][X] = 1;
                Point tuple;
                tuple.h = H;
                tuple.x = X;
                tuple.y = Y - 1;
                que.push(tuple);
                isChanged = true;
            }
            // 아래쪽
            if (Y < y - 1 && arr[H][Y + 1][X] == 0) {
                arr[H][Y + 1][X] = 1;
                Point tuple;
                tuple.h = H;
                tuple.x = X;
                tuple.y = Y + 1;
                que.push(tuple);
                isChanged = true;
            }
            // 천장
            if (H > 0 && arr[H - 1][Y][X] == 0) {
                arr[H - 1][Y][X] = 1;
                Point tuple;
                tuple.h = H - 1;
                tuple.x = X;
                tuple.y = Y;
                que.push(tuple);
                isChanged = true;
            }
            // 바닥
            if (H < h - 1 && arr[H + 1][Y][X] == 0) {
                arr[H + 1][Y][X] = 1;
                Point tuple;
                tuple.h = H + 1;
                tuple.x = X;
                tuple.y = Y;
                que.push(tuple);
                isChanged = true;
            }
        }

        if (isChanged) {
            sum++;
        }



//        /// print
//        for (int k = 0; k < h; ++k) {
//            for (int i = 0; i < y; ++i) {
//                for (int j = 0; j < x; ++j) {
//                    cout << arr[k][i][j] << " ";
//                }
//                cout << endl;
//            }
//        }
//
//        /// print


    }

    bool complete = true;
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                if (arr[k][i][j] == 0) {
                    complete = false;
                }
            }
        }
    }


    if (complete) {
        cout << sum;
    } else {
        cout << -1;
    }

    return 0;
}


