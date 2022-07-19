
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int x, y;
bool isFind = false;
vector<pair<int, int>> vec;

void printMap(int **&farm) {
    // 출력
    for (int i = 0; i < y; ++i) {
        for (int k = 0; k < x; ++k) {
            cout << farm[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void setCheck(int **map, int xp, int yp) {

    if (map[yp][xp] == 1) {
        map[yp][xp] = 2;

        //cout << xp << ", " << yp << ": " << number << endl;
        //printMap(map);

        if (yp == y - 1 && xp == x - 1) {
            //cout << "찾음!" << endl;
            isFind = true;
            return;
        }

        // 위
        if (yp != 0 && map[yp - 1][xp] == 1) {
            pair<int, int> pa;
            pa.first = xp;
            pa.second = yp - 1;
            vec.push_back(pa);
        }

        // 왼쪽
        if (xp != 0 && map[yp][xp - 1] == 1) {
            pair<int, int> pa;
            pa.first = xp - 1;
            pa.second = yp;
            vec.push_back(pa);
        }

        // 오른쪽
        if (xp != x - 1 && map[yp][xp + 1] == 1) {
            pair<int, int> pa;
            pa.first = xp + 1;
            pa.second = yp;
            vec.push_back(pa);
        }

        // 아래
        if (yp != y - 1 && map[yp + 1][xp] == 1) {
            pair<int, int> pa;
            pa.first = xp;
            pa.second = yp + 1;
            vec.push_back(pa);
        }
    }
}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> y >> x;
    // farm[y][x]
    int **farm = new int *[y]; //선언하고자 하는 이차원 배열의 행의 수 만큼 동적 할당
    for (int i = 0; i < y; i++) //각각의 인덱스에 선언하고자 하는 배열의 크기만큼을 가르키게 함.
        farm[i] = new int[x];

    for (int i = 0; i < y; ++i) {
        string text;
        cin >> text;
        for (int j = 0; j < x; ++j) {
            char ch = text[j];
            int num = ch - '0';
            farm[i][j] = num;
        }
    }

    int number = 0;

    pair<int, int> pa;
    pa.first = 0;
    pa.second = 0;
    vec.push_back(pa);

    while (isFind == false) {
        number++;
        vector<pair<int, int>> tempV;

        for (pair<int, int> pai: vec) {
            tempV.push_back(pai);
        }

        vec.clear();

        for (pair<int, int> pai: tempV) {
            setCheck(farm, pai.first, pai.second);
        }
        cout << number << endl;
        printMap(farm);
    }
    cout << number;


    return 0;
}
