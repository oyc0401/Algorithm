
#include <iostream>
#include <map>
#include <iomanip>
#include "vector"

using namespace std;

int main() {
    int sum[9];

    for (int &i: sum) {
        cin >> i;
    }
    int big = sum[0], small = sum[0];

    for (int i: sum) {
        if (i <= small) {
            small = i;
        }
        if (i >= big) {
            big = i;
        }
    }

    cout << big << endl << small;


    return 0;
}

