#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


int a, b;
vector<int> vec;

void print(int n, string text, int depth) {

    for (int i = n; i < a; ++i) {
        // cout << "def: " << def << ", n: " << n << endl;
        string te = text + to_string(vec[i]) + " ";

        if (depth == b) {
            cout << te << endl;
        } else {
            print(i , te, depth + 1);
        }
    }
}



// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> a >> b;

    map<int,bool> myMap;
    for (int i = 0; i < a; ++i) {
        int num;
        cin>>num;
        myMap[num]= true;
    }

    for (pair<int,bool> pa:myMap) {
        if(pa.second){
            vec.push_back(pa.first);
        }
    }

    a= vec.size();
    std::sort(vec.begin(), vec.end());

    print(0, "", 1);

}
