
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
    map<int, vector<int>> myMap;

    cin >> index;

    for (int i = 0; i < index; ++i) {
        int x;
        int y;
        cin >> x >> y;
        myMap[x].push_back(y);
    }

    for (pair<int, vector<int>> pa: myMap) {
        std::sort(pa.second.begin(), pa.second.end());
        for (int y: pa.second) {
            cout << pa.first <<" "<< y << "\n";
        }
    }


    return 0;
}
