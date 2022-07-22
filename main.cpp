
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

void printCurrent() {
//    int big=my>you?my:you;
//    // 프린트
//    for (int k = 0; k < big*2; ++k) {
//        cout << k << ": " << "(" << positions[k] << ')' << ", ";
//    }
//    cout << "\n";
//    for (int k = 0; k < big*2; ++k) {
//        cout << k << ": " << "(" << ways[k] << ')' << ", ";
//    }
//    cout << "\n";
}

pair<int, int> getways(int my, int you) {
    int positions [300005];
    int ways [300005];
    if (my == you) {
        pair<int, int> pa;
        pa.first = 0;
        pa.second = 1;
        return pa;
    }

    vector<int> vec;
    vec.push_back(you);
    positions[you] = -1;
    ways[you] = 1;

    for (int i = 1; true; ++i) {
        ///  cout << "i: " << i << endl;

        // 내 위치의 시간이 결정되면 끝
        if (positions[my] != 0) {
            pair<int, int> pa;
            pa.first = positions[my];
            pa.second = ways[my];
            return pa;
        }

        // 새로운 위치를 추가
        vector<int> tempVec;
        if (positions[my] == 0) {
            for (int j = 0; j < vec.size(); ++j) {
                int pos = vec[j];
                //cout <<"vec: "<< pos << endl;
                int a = pos - 1;
                int b = pos + 1;

                // -1칸
                if (a >= 0) {
                    if (positions[a] == 0 || positions[a] == i) {
                        ways[a] += ways[pos];
                    }

                    if (positions[a] == 0) {
                        positions[a] = i;
                        tempVec.push_back(a);
                    }
                }

                // +1칸
                if (positions[b] == 0 || positions[b] == i) {
                    ways[b] += ways[pos];
                }
                if (positions[b] == 0) {
                    positions[b] = i;
                    tempVec.push_back(b);

                }

                // *2칸
                if (pos % 2 == 0) {
                    int c = pos / 2;
                    if (c != 0) {
                        if (positions[c] == 0 || positions[c] == i) {
                            ways[c] += ways[pos];
                        }
                        if (positions[c] == 0) {
                            positions[c] = i;
                            tempVec.push_back(c);

                        }
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
            ///    cout << "\n";

        }
        printCurrent();

    }
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int my, you;
    cin >> my >> you;

    pair<int, int> pai = getways(my, you);
    cout << pai.first << "\n" << pai.second;

    return 0;
}


