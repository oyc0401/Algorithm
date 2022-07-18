
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index;
    map<int, int> myMap;

    cin >> index;

    for (int i = 0; i < index; ++i) {
        int num;
        cin >> num;
        myMap[num]++;
    }

    int how;
cin>>how;
    for (int i = 0; i < how; ++i) {
        int a;
        cin>>a;
      cout<<  myMap[a]<<" ";
    }


    return 0;
}
