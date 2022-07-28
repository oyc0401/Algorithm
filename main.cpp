
#include <iostream>

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

    int x, y;
    cin >> x >> y;


    int **arr = new int *[y]; //선언하고자 하는 이차원 배열의 행의 수 만큼 동적 할당
    for (int i = 0; i < y; i++) //각각의 인덱스에 선언하고자 하는 배열의 크기만큼을 가르키게 함.
        arr[i] = new int[x];

    queue<pair<int, int>> que;

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            cin >> arr[i][j];
        }
    }

    int sum = 0;

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if (arr[i][j] == 1) {
                pair<int, int> pa;
                pa.first = j;
                pa.second = i;
                que.push(pa);
            }
        }
    }


    while (!que.empty()) {
        int size = que.size();
        bool isChanged= false;

        for (int i = 0; i < size; ++i) {
            pair<int, int> pa = que.front();
            que.pop();
            const int X = pa.first;
            const int Y = pa.second;

            // cout<<"i: "<<i<<", x: "<<X<<", y: "<<Y<<", sum: "<<sum<<endl;
            //cout << "sum: " << sum << ", x: " << X << ", y: " << Y << endl;
            // 왼쪽
            if (X > 0 && arr[Y][X - 1] == 0) {
                arr[Y][X - 1] = 1;
                pair<int, int> tuple;
                tuple.first = X - 1;
                tuple.second = Y;
                que.push(tuple);
                isChanged= true;
            }
            // 오른쪽
            if (X < x - 1 && arr[Y][X + 1] == 0) {
                arr[Y][X + 1] = 1;
                pair<int, int> tuple;
                tuple.first = X + 1;
                tuple.second = Y;
                que.push(tuple);
                isChanged= true;
            }
            // 위쪽
            if (Y > 0 && arr[Y - 1][X] == 0) {
                arr[Y - 1][X] = 1;
                pair<int, int> tuple;
                tuple.first = X;
                tuple.second = Y - 1;
                que.push(tuple);
                isChanged= true;
            }
            // 아래쪽
            if (Y < y - 1 && arr[Y + 1][X] == 0) {
                arr[Y + 1][X] = 1;
                pair<int, int> tuple;
                tuple.first = X;
                tuple.second = Y + 1;
                que.push(tuple);
                isChanged= true;
            }
        }

        if(isChanged){
            sum++;
        }



//        /// print
//        for (int i = 0; i < y; ++i) {
//            for (int j = 0; j < x; ++j) {
//                cout << arr[i][j] << " ";
//            }
//            cout << endl;
//        }
//        /// print


    }

    bool complete= true;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if(arr[i][j]==0){
                complete= false;
            }
        }
    }

    if(complete){
        cout << sum;
    }else{
        cout<<-1;
    }



//    /// print
//    for (int i = 0; i < y; ++i) {
//        for (int j = 0; j < x; ++j) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//    /// print


    return 0;
}


