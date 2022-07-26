
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;
//14
//1 4
//2 4
//4 4
//3 5
//0 6
//5 7
//7 8
//3 8
//5 9
//6 10     //10
//8 11
//8 12
//2 13
//12 14


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ind;
    cin >> ind;
    map<int, priority_queue<int, vector<int>, greater<int>>> myMap;

    for (int i = 0; i < ind; ++i) {
        int a, b;
        cin >> a >> b;
        myMap[b].push(a);
    }

    int where = 0;
    int sum = 0;

    for (pair<int, priority_queue<int, vector<int>, greater<int>>> pa: myMap) {
        int i = pa.first;
        priority_queue<int, vector<int>, greater<int>> qu = pa.second;
        while (!qu.empty()) {

            if (qu.top() >= where) {
                where = i;
                //cout<<i<< " "<< qu.top()<<endl;
                sum++;
            }
            qu.pop();
        }
    }

    cout << sum;


    return 0;
}


