#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

int a;

int divi;

map<int, int> myMap;
map<int, bool> check;


/// 이 함수는 왜 안될까? 미래의 나는 알겠지?
int pows(int zi) {

    if (check[zi]) {
        return myMap[zi] % divi;
    }


    cout << zi << endl;

    if (zi % 2 == 0) {
        unsigned long long num = (((pows(zi / 2) % divi) * (pows(zi / 2)) % divi)) % divi;
        myMap[zi] = num;
        check[zi] = true;
        return num;
    } else {
        unsigned long long t = ((pows((zi - 1) / 2) % divi) * (pows((zi - 1) / 2) % divi)) % divi;


        unsigned long long num = ((a % divi) * (t % divi)) % divi;
        if (zi == 51) {
            cout << zi << "나누기 2: ";
            cout << pows((zi - 1) / 2) << endl;
            cout << zi << "나누기 2 x: ";
            cout << 33554432 * 33554432 << endl;
//            cout<<a % divi<<endl;
//            cout<<t % divi<<endl;
//            cout<<((a % divi) * (t % divi))<<endl;
//            cout<<num<<endl;
        }
        myMap[zi] = num;
        check[zi] = true;
        return num;
    }
}


long long int f(long long int y) {
    if (y == 1) return a % divi;

    long long int k = f(y / 2) % divi;

    if (y % 2 == 0) return k * k % divi;
    else return k * k % divi * a % divi;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int zisu;

    cin >> a >> zisu >> divi;
    cout << f(zisu);


    // 이건 왜 안될까?
//    myMap[1] = a % divi;
//    check[1] = true;
//    long long number = pows(zisu);
//    cout << number;


// 2147483647 2147483645 1000000
// 2147483647 214748364 2147483645




}
