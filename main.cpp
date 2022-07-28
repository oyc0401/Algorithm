
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;


//4
//1 0 0 0
//0 1 0 0
//0 0 1 1
//0 0 1 1



int white = 0;
int blue = 0;


void cut(int x, int y, int size, int **arr) {
    // 다른게 섞이면 자르기
    int thisSection = arr[y][x];

    ///cout<<"("<<x<<", "<<y<<"), 길이: "<<size<<", 이번 색: "<<thisSection<<endl;

//    for (int i = y; i < y + size; ++i) {
//        for (int j = x; j < x + size; ++j) {
//            cout<<arr[i][j]<<" ";
//        }
//        cout << endl;
//    }
//    cout<<endl;

    if(size>1){
        for (int i = y; i < y + size; ++i) {
            for (int j = x; j < x + size; ++j) {
                // 다른게 섞이면 실패
                if (arr[i][j] != thisSection) {
                    int half = size / 2;
                    cut(x, y, half, arr);
                    cut(x + half, y, half, arr);
                    cut(x, y + half, half, arr);
                    cut(x + half, y + half, half, arr);
                    return;
                }

            }
        }
    }


    if (thisSection == 0) {
        //cout<<"white +1\n";
        white++;
    } else {
       // cout<<"blue +1\n";
        blue++;
    }
    //cout<<endl;


}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width;
    cin >> width;

    int **arr = new int *[width]; //선언하고자 하는 이차원 배열의 행의 수 만큼 동적 할당
    for (int i = 0; i < width; i++) //각각의 인덱스에 선언하고자 하는 배열의 크기만큼을 가르키게 함.
        arr[i] = new int[width];

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> arr[i][j];
        }
    }

    cut(0, 0, width, arr);

    cout<<white<<endl<<blue;


    return 0;
}


