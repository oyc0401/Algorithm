
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

int myMap[1000001];

int getNum(int num) {
    myMap[1] = 0;
    for (int i = 2; i <= num; ++i) {

        myMap[i] = myMap[i - 1] + 1;

        // 2로 나눠지면 잘 되는지 확인
        if (i % 2 == 0) {
            myMap[i] = min(myMap[i], myMap[i / 2] + 1);
        }

        // 3으로 나누는게 최고가 아니였어!
        if (i % 3 == 0) {
            myMap[i] = min(myMap[i], myMap[i / 3] + 1);
        }
    }
    return myMap[num];
}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int number;
    cin >> number;
    cout << getNum(number);

    return 0;
}
