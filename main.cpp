
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int positions[300002];

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int my, you;
    cin >> my >> you;
    if (my == you) {
        cout << 0 << endl;
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
            cout << positions[my];
            return 0;
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
//        // 프린트
//        for (int k = 0; k < you * 2; ++k) {
//            // cout<<positions[i]<<", ";
//            //cout << "[" << k << ": " << positions[k] << ']' << ", ";
//            cout << k << ": " << "(" << positions[k] << ')' << ", ";
//        }
//        cout << "\n";

    }


    return 0;
}


