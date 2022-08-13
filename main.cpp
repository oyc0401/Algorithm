#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <stack>


using namespace std;

class quadruple {
public:
    int Rx, Ry;
    int Bx, By;

    string toString() {
        return "(" + to_string(Rx) + ", " + to_string(Ry) + "), (" + to_string(Bx) + ", " + to_string(By) + ")";
    }
};


string *board;

enum direction {
    top, bottom, left, right
};

void MoveR(quadruple &current, int mX, int mY) {
    // 빨강
    if (board[current.Ry][current.Rx] == 'O') {
        return;
    }
    if (board[current.Ry + mY][current.Rx + mX] == 'O') {
        current.Ry += mY;
        current.Rx += mX;
        return;
    }

    while (board[current.Ry + mY][current.Rx + mX] == '.'
           && !(current.Ry + mY == current.By && current.Rx + mX == current.Bx)) {
        current.Ry += mY;
        current.Rx += mX;
        if (board[current.Ry + mY][current.Rx + mX] == 'O') {
            current.Ry += mY;
            current.Rx += mX;
            return;
        }
    }

}

void MoveB(quadruple &current, int mX, int mY) {
    // 파랑
    if (board[current.By][current.Bx] == 'O') {
        return;
    }
    if (board[current.By + mY][current.Bx + mX] == 'O') {
        current.By += mY;
        current.Bx += mX;
        return;
    }

    while (board[current.By + mY][current.Bx + mX] == '.'
           && !(current.By + mY == current.Ry && current.Bx + mX == current.Rx)) {
        current.By += mY;
        current.Bx += mX;

        if (board[current.By + mY][current.Bx + mX] == 'O') {
            current.By += mY;
            current.Bx += mX;
            return;
        }
    }

}

quadruple tilt(quadruple current, direction direc) {

    int mY;
    int mX;

    switch (direc) {

        case direction::top:
            mY = -1;
            mX = 0;
            if (current.Ry < current.By) {
                MoveR(current, mX, mY);
                MoveB(current, mX, mY);
            } else {
                MoveB(current, mX, mY);
                MoveR(current, mX, mY);
            }
            return current;

        case direction::bottom:
            mY = +1;
            mX = 0;
            if (current.Ry > current.By) {
                MoveR(current, mX, mY);
                MoveB(current, mX, mY);
            } else {
                MoveB(current, mX, mY);
                MoveR(current, mX, mY);
            }
            return current;
        case direction::left:
            mY = 0;
            mX = -1;
            if (current.Rx < current.Bx) {
                MoveR(current, mX, mY);
                MoveB(current, mX, mY);
            } else {
                MoveB(current, mX, mY);
                MoveR(current, mX, mY);
            }
            return current;
        case direction::right:
            mY = 0;
            mX = +1;
            if (current.Rx > current.Bx) {
                MoveR(current, mX, mY);
                MoveB(current, mX, mY);
            } else {
                MoveB(current, mX, mY);
                MoveR(current, mX, mY);
            }
            return current;
    }

}


//void BFS(int num) {
//    queue<int> que;
//
//    // 처음 큐 넣기
//    que.push(num);
//
//    // 큐 순환
//    while (!que.empty()) {
//        /// cout<<que.front()<<" ";
//
//        if (!BFS_check[que.front()]) {
//            BFS_check[que.front()] = true;
//            printQue.push(que.front());
//
//            for (int n: edge[que.front()]) {
//                que.push(n);
//            }
//        }
//
//        que.pop();
//    }
//
//
//}


void startGame(quadruple moved,int N,int M){
    /// print
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (moved.Rx == j && moved.Ry == i && moved.Bx == j && moved.By == i) {
                cout << "P" << " ";
            } else if (moved.Rx == j && moved.Ry == i) {
                cout << "R" << " ";
            } else if (moved.Bx == j && moved.By == i) {
                cout << "B" << " ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }

    char where;
    cin >> where;
    while (where != 'q') {

        if (where == 'w') {
            moved = tilt(moved, direction::top);
        } else if (where == 's') {
            moved = tilt(moved, direction::bottom);
        } else if (where == 'a') {
            moved = tilt(moved, direction::left);
        } else if (where == 'd') {
            moved = tilt(moved, direction::right);
        }

        /// print
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (moved.Rx == j && moved.Ry == i && moved.Bx == j && moved.By == i) {
                    cout << "P" << " ";
                } else if (moved.Rx == j && moved.Ry == i) {
                    cout << "R" << " ";
                } else if (moved.Bx == j && moved.By == i) {
                    cout << "B" << " ";
                } else {
                    cout << board[i][j] << " ";
                }
            }
            cout << endl;
        }
        cin >> where;
    }
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    board = new string[N]; //선언하고자 하는 이차원 배열의 행의 수 만큼 동적 할당

    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    quadruple position{};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 'R') {
                position.Ry = i;
                position.Rx = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'B') {
                position.By = i;
                position.Bx = j;
                board[i][j] = '.';
            }
        }
    }


//    for (int i = 0; i < N; ++i) {
//        cout << board[i] << " ";
//        cout << endl;
//    }
//
//    cout << "처음: " << position.toString() << endl;


    startGame(position,N,M);


//    quadruple moved = tilt(position, direction::top);
//    cout << moved.toString() << endl;
//
//
//    moved = tilt(moved, direction::left);
//    cout << moved.toString() << endl;
//
//    moved = tilt(moved, direction::right);
//    cout << moved.toString() << endl;
//
//    moved = tilt(moved, direction::bottom);
//    cout << moved.toString() << endl;

    return 0;
}


