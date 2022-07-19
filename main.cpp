
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int x, y;
int fin = 0;


void setCheck(int **&map, int xp, int yp) {
    if (map[yp][xp] == 1) {
        map[yp][xp] = 2;

        // 위
        if (yp != 0 && map[yp - 1][xp]) {
            setCheck(map, xp, yp - 1);
        }

        // 왼쪽
        if (xp != 0 && map[yp][xp - 1]) {
            setCheck(map, xp - 1, yp);
        }

        // 오른쪽
        if (xp != x-1 && map[yp][xp + 1]) {
            setCheck(map, xp + 1, yp);
        }

        if (yp != y-1 && map[yp + 1][xp]) {
            setCheck(map, xp, yp + 1);
        }

    }


}

void findArea(int **&map) {
    for (int i = 0; i < y; ++i) {
        for (int k = 0; k < x; ++k) {
            if (map[i][k] == 1) {
                setCheck(map, k, i);
                fin++;
            }
        }
    }

}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int how;
    cin >> how;

    for (int r = 0; r < how; ++r) {
        fin = 0;
        int ind;
        cin >> x >> y >> ind;
        // farm[y][x]
        int **farm = new int *[y]; //선언하고자 하는 이차원 배열의 행의 수 만큼 동적 할당
        for (int i = 0; i < y; i++) //각각의 인덱스에 선언하고자 하는 배열의 크기만큼을 가르키게 함.
            farm[i] = new int[x];


        for (int i = 0; i < ind; ++i) {
            int xp, yp;
            cin >> xp >> yp;
            farm[yp][xp] = 1;
        }




        findArea(farm);

        cout << fin << endl;

//        // 출력
//        for (int i = 0; i < y; ++i) {
//            for (int k = 0; k < x; ++k) {
//                cout << farm[i][k] << " ";
//            }
//            cout << endl;
//        }

    }


    return 0;
}
