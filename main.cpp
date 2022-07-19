
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int sum(int number) {


    if (number == 1) {
        return 1;
    }
    if (number == 2) {
        return 2;
    }
    if (number == 3) {
        return 4;
    }

    return sum(number - 1) + sum(number - 2) + sum(number - 3);
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int index;
    cin >> index;
    for (int i = 0; i < index; ++i) {
        int number;
        cin >> number;
        cout << sum(number) << "\n";
    }


    return 0;
}
