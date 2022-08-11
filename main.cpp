#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <iomanip>

using namespace std;
int INF = 1000000;
int sum;
int **original;
int **arr;
int ind;

//4
//7
//10 30 10 50 100 20 40
//20 40 30 50 60 20 80
//5
//50 10 100 20 40
//30 50 70 10 60
//5
//50 10 100 20 40
//30 50 70 10 60
//5
//50 10 100 20 40
//30 50 70 10 60


void printArr() {
//    for (int i = 0; i < 2; ++i) {
//        for (int k = 0; k <= ind + 1; ++k) {
//            cout << setw(8) << arr[i][k] << " ";
//        }
//        cout << endl;
//    }
}

int whoIsSmall(int a, int b, int c, int d) {
    if (a < b && a < c && a < d) {
        return 1;
    }
    if (b < a && b < c && b < d) {
        return 2;
    }
    if (c < a && c < b && c < d) {
        return 3;
    }
    if (d < a && d < b && d < c) {
        return 4;
    }
    return 1;
}

void downNum(int row, int index) {
    if (arr[row][index] >= INF - 100000) {
        return;
    }

    int orig = original[row][index];
    if (row == 0) {
        arr[0][index - 1] -= orig;
        arr[0][index + 1] -= orig;
        arr[1][index] -= orig;
    } else {
        arr[1][index - 1] -= orig;
        arr[1][index + 1] -= orig;
        arr[0][index] -= orig;
    }

}

void deleteSticker(int row, int index) {

    if (row == 0) {
        downNum(0, index - 1);
        downNum(0, index + 1);
        downNum(1, index);

        arr[0][index] = INF;
        arr[0][index - 1] = INF;
        arr[0][index + 1] = INF;
        arr[1][index] = INF;
    } else {
        downNum(1, index - 1);
        downNum(1, index + 1);
        downNum(0, index);

        arr[1][index] = INF;
        arr[1][index - 1] = INF;
        arr[1][index + 1] = INF;
        arr[0][index] = INF;
    }

}


void sticker(int index) {
    if (index == ind + 1) {
        return;
    }
//    if (arr[0][index] >= INF - 100000 && arr[1][index] >= INF - 100000) {
//        return;
//    }

    int a = arr[0][index];
    int b = arr[0][index + 1];
    int c = arr[1][index];
    int d = arr[1][index + 1];

    int big = whoIsSmall(a, b, c, d);
    //cout << big << endl;

    if (big == 1) {
        sum += original[0][index];
        deleteSticker(0, index);

        printArr();
        sticker(index + 1);
    } else if (big == 2) {
        sum += original[0][index + 1];
        deleteSticker(0, index + 1);

        printArr();
        sticker(index + 2);
    } else if (big == 3) {
        sum += original[1][index];
        deleteSticker(1, index);

        printArr();
        sticker(index + 1);
    } else {
        sum += original[1][index + 1];
        deleteSticker(1, index + 1);

        printArr();
        sticker(index + 2);
    }


}

void going() {
    sum = 0;
    cin >> ind;




    for (int i = 0; i < 100000 + 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            arr[j][i] = 0;
            original[j][i] = 0;
        }
    }


    for (int i = 1; i <= ind; ++i) {
        int a;
        cin >> a;
        original[0][i] = a;
        arr[0][i - 1] += a;
        arr[0][i + 1] += a;
        arr[1][i] += a;

    }
    for (int i = 1; i <= ind; ++i) {
        int a;
        cin >> a;
        original[1][i] = a;
        arr[1][i - 1] += a;
        arr[1][i + 1] += a;
        arr[0][i] += a;
    }


    arr[0][0] = INF;
    arr[1][0] = INF;
    arr[0][ind + 1] = INF;
    arr[1][ind + 1] = INF;

    printArr();

    sticker(1);

    cout << sum<<"\n";
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt;
    cin >> cnt;

    arr = new int *[2]; //행의 크기가 3인 이차원 배열
    for (int i = 0; i < 2; i++) //각각의 행에 길이가 4인 배열을 할당
        arr[i] = new int[100000 + 2];

    original = new int *[2]; //행의 크기가 3인 이차원 배열
    for (int i = 0; i < 2; i++) //각각의 행에 길이가 4인 배열을 할당
        original[i] = new int[100000 + 2];

    for (int i = 0; i < cnt; ++i) {
        going();
    }

}


