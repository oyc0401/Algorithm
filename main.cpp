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

    int index;
    cin >> index;
    stack<int> sta;

    for (int i = 0; i < index; ++i) {
        int a;
        cin >> a;
        if(a==0){
            sta.pop();
        }else{
            sta.push(a);
        }
    }

    int sum=0;
    while (!sta.empty()) {
        sum+=sta.top();
        sta.pop();
    }

    cout<<sum;


}


