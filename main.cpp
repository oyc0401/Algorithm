#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index;
    cin >> index;
    vector<int> oriVec;

    vector<int> vec;
    map<int, int> myMap;


    for (int i = 0; i < index; ++i) {
        int n;
        cin >> n;
        oriVec.push_back(n);
        vec.push_back(n);
    }

    std::sort(vec.begin(), vec.end());

    int x=1;

    for (int i = 0; i < index; ++i) {
        int num = vec[i];

        if(myMap[num]==0){
            myMap[num]=x;
            x++;
        }
    }

    for (int num:oriVec) {
        cout<<myMap[num]-1<<" ";

    }


}


