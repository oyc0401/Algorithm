
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
    int a, b;
    cin >> a >> b;

    map<string, int> myMap;

    for (int i = 0; i < a; ++i) {
        string name;
        cin >> name;
        myMap[name]++;
    }

    for (int i = 0; i < b; ++i) {
        string name;
        cin >> name;
        myMap[name]++;
    }

    int count = 0;
    vector<string> names;

    for (pair<string, int> pa: myMap) {
        if (pa.second == 2) {
            count++;
            names.push_back(pa.first);
        }
    }

    cout<<count<<endl;
    for (string name: names) {
        cout << name << "\n";
    }


    return 0;
}


