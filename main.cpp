
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int positions[300002];



void printArr() {
//    // 프린트
//    for (int k = 0; k < you * 2; ++k) {
//        // cout<<positions[i]<<", ";
//        //cout << "[" << k << ": " << positions[k] << ']' << ", ";
//        cout << k << ": " << "(" << positions[k] << ')' << ", ";
//    }
//    cout << "\n";
}

int getNum(int my, int you) {
    if (my == you) {
        //cout << 0 << endl;
        return 0;
    }

    vector<int> vec;
    vec.push_back(you);
    positions[you] = -1;


    for (int i = 1; true; ++i) {
        //cout << "i: " << i << endl;

        // 내 위치의 시간이 결정되면 끝
        if (positions[my] != 0) {
            //cout << "답: " << positions[my] << endl;
            return positions[my];

        }

        // 새로운 위치를 추가
        vector<int> tempVec;
        if (positions[my] == 0) {
            for (int j = 0; j < vec.size(); ++j) {
                int pos = vec[j];
                //cout <<"vec: "<< pos << endl;
                int a = pos - 1;
                int b = pos + 1;

                if (a >= 0 && positions[a] == 0) {
                    positions[a] = i;
                    tempVec.push_back(a);
                }
                if (positions[b] == 0) {
                    positions[b] = i;
                    tempVec.push_back(b);
                }
                if (pos % 2 == 0) {
                    int c = pos / 2;
                    if (c != 0 && positions[c] == 0) {
                        positions[c] = i;
                        tempVec.push_back(c);
                    }
                }
            }
            // vec을 temp로 바꿈
            vec.clear();
            //cout << "추가된 원소: ";
            for (int val: tempVec) {
                // cout << val << ", ";
                vec.push_back(val);
            }
            //cout << "\n";

        }


    }

}

vector<int> posList(int my, int you) {
    int currentPosition = my;
    vector<int> vec;


    for (int i = 1; true; ++i) {
        vec.push_back(currentPosition);
       // cout << currentPosition << " ";
        //cout << "i: " << i << endl;

        // 내 위치의 시간이 결정되면 끝
        if (currentPosition == you) {
            return vec;
        }
        int bigNumber = 100000000;
        int a = currentPosition - 1;
        int b = currentPosition + 1;
        int c = currentPosition * 2;

        int A = bigNumber;
        int B = bigNumber;
        int C = bigNumber;

        // A 설정
        if (a >= 0) {
            if (positions[a] != 0) {
                A = positions[a];
            }
        }

        // B 설정
        if (positions[b] != 0) {
            B = positions[b];
        }

        // C 설정
        if (currentPosition != 0 && positions[c] != 0) {
            C = positions[c];
        }


        int small = A < B ? A : B;
        small = small < C ? small : C;


        if (small == A) {
            currentPosition = a;
        } else if (small == B) {
            currentPosition = b;
        } else if (small == C) {
            currentPosition = c;
        }


    }
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int my, you;
    cin >> my >> you;


    int a = getNum(my, you);
    cout << a << endl;
    vector<int> myVec = posList(my, you);

    for (int pos: myVec) {
        cout << pos << " ";
    }


    return 0;
}


