
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    int numbers[10001]{0};

    cin >> a;
    int number;
    for (int i = 0; i < a; ++i) {
        cin >> number;
        numbers[number]++;
    }

    for (int i = 1; i <= 10000; ++i) {
        for (int k = 0; k < numbers[i]; ++k) {
            cout << i << "\n";
        }
    }


    return 0;
}
