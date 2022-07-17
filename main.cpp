
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int len, num;
vector<bool> vec;

int nextNumber(int where) {
    for (int j = 0; j < num; ++j) {
        int next = where + 1;
        next %= len;
        if (vec[next]) {
//               cout<<"O";
            where++;
            where = where % len;
        } else {
            where++;
            where %= len;

            while (!vec[where]) {
//                   cout<<"X";
//                 cout<<where;
                where++;
                where = where % len;
            }
        }
    }
    return where;
}

/// 1초: 1억번
int main() {
///    ios_base::sync_with_stdio(false);
///    cin.tie(NULL);
///    cout.tie(NULL);

    vector<int> numbers;
    cin >> len >> num;

    for (int i = 0; i < len; ++i) {
        vec.push_back(true);
    }
    int where = -1;
    for (int i = 0; i < len; ++i) {
        where = nextNumber(where);
        vec[where] = false;
        numbers.push_back(where + 1);
    }


    cout << "<";
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i];
        if (i == numbers.size() - 1) {
            cout << ">";
        } else {
            cout << ", ";
        }
    }


    return 0;
}
