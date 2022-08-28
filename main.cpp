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

    int ind, money;
    cin >> ind >> money;

    stack<int> sta;


    for (int i = 0; i < ind; ++i) {
        int a;
        cin >> a;
        sta.push(a);
    }

    int current=0;
    int sum=0;

   while (current!=money){
   // for (int i = 0; i < 10; ++i) {


        int top=sta.top();
        if(money-current-top>=0){
            current+=top;
            sum++;
        }else{
            sta.pop();
        }

       // cout<<current<<endl;
    }

    cout<<sum;




}
