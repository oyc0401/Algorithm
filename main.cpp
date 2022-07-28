
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

    map<int, bool> myMap;

    int index;
    cin >> index;


    for (int i = 0; i < index; ++i) {
        string order;

        cin >> order;
        int num;


        if (order == "add") {
            cin >> num;

            myMap[num] = true;
        } else if (order == "remove") {
            cin >> num;

            myMap[num] = false;
        } else if (order == "check") {
            cin >> num;

            cout << myMap[num] << '\n';

        } else if (order == "toggle") {
            cin >> num;

            if (myMap[num]) {
                myMap[num] = false;
            } else {
                myMap[num] = true;
            }

        } else if (order == "all") {
            for (int j = 1; j <= 20; ++j) {
                myMap[j] = true;
            }

        } else if (order == "empty") {
            for (int j = 1; j <= 20; ++j) {
                myMap[j] = false;
            }
        }
    }


    return 0;
}


