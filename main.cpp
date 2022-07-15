
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

map<int, int> setMap(int num) {
    map<int, int> myMap;
    while (num != 1) {
        // cout << num << endl;
        for (int i = 2;; ++i) {
            if (num % i == 0) {
                myMap[i]++;
                num = num / i;
                break;
            }
        }
    }
    return myMap;
}

int main() {

    int a, b;

    cin >> a >> b;
    map<int, int> mapA = setMap(a);
    map<int, int> mapB = setMap(b);


    // 최대 공약수 구하기
    int maxGong = 1;

    for (pair<int, int> po: mapB) {
        int aNum = mapA[po.first];
        int bNum = po.second;
        if (aNum != 0) {
            int min = aNum < bNum ? aNum : bNum;
            for (int i = 0; i < min; ++i) {
                maxGong *= po.first;
            }
        }
    }

    cout << maxGong<<endl;

    /// 최소 공배수 구하기

    int minGongbae = (a*b)/maxGong;

    cout<<minGongbae;


    return 0;
}
