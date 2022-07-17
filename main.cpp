
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

// 1초: 1억번
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);




    int index;
    map<int, vector<string>> myMap;

    cin >> index;

    for (int i = 0; i < index; ++i) {
        int age;
        string name;
        cin >> age >> name;
        myMap[age].push_back(name);
    }

    for (pair<int, vector<string>> pa: myMap) {
        for (string name: pa.second) {
            cout << pa.first <<" "<< name << "\n";
        }
    }


    return 0;
}
