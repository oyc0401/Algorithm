
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int my, you;
int positions[300005]{};
int inital = -12;

void printCurrent() {
//    int big = my > you ? my : you;
//    // 프린트
//    for (int k = 0; k < big * 2; ++k) {
//        cout << k << ": " << "(" << positions[k] << ')' << ", ";
//    }
//    cout << "\n";

}

int getways(int my, int you) {


    if (my == you) {
        return 0;
    }

    vector<int> vec;
    vec.push_back(you);
    positions[you] = -1;
    int yours = you;
    while (yours != 0 && yours % 2 == 0) {
        yours /= 2;
        positions[yours] = 0;
        vec.push_back(yours);
    }


    printCurrent();


    for (int i = 1; true; ++i) {
       /// cout << "i: " << i << endl;

        // 내 위치의 시간이 결정되면 끝
        if (positions[my] != inital) {
            return positions[my];
        }

        // 새로운 위치를 추가
        vector<int> tempVec;
        if (positions[my] == inital) {
            for (int j = 0; j < vec.size(); ++j) {
                int pos = vec[j];
                //cout <<"vec: "<< pos << endl;
                int a = pos - 1;
                int b = pos + 1;


                // -1칸
                if (a >= 0 && positions[a] == inital) {
                    positions[a] = i;
                    tempVec.push_back(a);
                    while (a != 0 && a % 2 == 0) {
                        a /= 2;
                        positions[a] = i;
                        tempVec.push_back(a);
                    }
                }


                // +1칸
                if (positions[b] == inital) {
                    positions[b] = i;
                    tempVec.push_back(b);
                    while (b != 0 && b % 2 == 0) {
                        b /= 2;
                        positions[b] = i;
                        tempVec.push_back(b);
                    }
                }

            }
            // vec을 temp로 바꿈
            vec.clear();
           /// cout << "추가된 원소: ";
            for (int val: tempVec) {
              ///  cout << val << ", ";
                vec.push_back(val);
            }
          ///  cout << "\n";

        }
        printCurrent();

    }
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> my >> you;

    for (int &n: positions) {
        n = inital;
    }

    cout << getways(my, you);

    return 0;
}


