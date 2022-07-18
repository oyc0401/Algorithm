
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
//
// 1
// 1 6 12 11

using namespace std;

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index, ans;
    map<string, int> myMap;
    string list[100001];

    cin >> index >> ans;

    for (int i = 1; i <= index; ++i) {
        string name;
        cin >> name;
        myMap[name] = i;
        list[i] = name;
    }

    for (int i = 0; i < ans; ++i) {
        string name;
        cin >> name;
        if(name[0]>='0' &&name[0]<='9'){
            int in= stoi(name);
            cout<<list[in]<<"\n";
        }else{
            cout<<myMap[name]<<"\n";
        }
    }


    return 0;
}
