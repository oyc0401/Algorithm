#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int lenght;
    cin >> lenght;
    vector<int> vec;


    map<int, int> myMap;

    for (int i = 0; i < lenght; ++i) {
        int a;
        cin >> a;
        vec.push_back(a);
        myMap[a]++;
    }

    double sum = 0;
    for (int n: vec) {
        sum += n;
    }


    cout << round(sum / lenght)+1-1<< endl;

    std::sort(vec.begin(), vec.end());

    double middle = vec[lenght / 2];
    cout << middle << endl;


    int big = 0;
    for (pair<int, int> pa: myMap) {
        if (big < pa.second) {
            big = pa.second;
        }
    }

    vector<int> bigs;
    for (pair<int, int> pa: myMap) {
        if(pa.second==big){
           bigs.push_back(pa.first);
        }
    }

    if(bigs.size()<2){
        cout<<bigs[0]<<endl;
    }else{
        cout<<bigs[1]<<endl;
    }


    cout<<vec[lenght-1]- vec[0];

}
