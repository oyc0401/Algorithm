#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


void go(){
    int len, num;
    cin >> len >> num;

    int arr[10];
    for (int i = 0; i <= 9; ++i) {
        arr[i]=0;
    }
    queue<pair<int, int>> que;
    for (int i = 0; i < len; ++i) {
        int a;
        cin >> a;
        arr[a]++;
        que.push(make_pair(i, a));
    }

    int sum = 0;



    while (!que.empty()) {
        int index = que.front().first;


        bool existBig= false;
        for (int i = que.front().second+1; i <= 9; ++i) {
            if(arr[i]!=0){
                existBig= true;
            }
        }

        if(existBig){
            que.push(que.front());
            que.pop();
        }else{
            sum++;
            if(index==num){
                cout<<sum<<'\n';
                que.pop();
                return;
            }else{
                arr[que.front().second]--;
                que.pop();
            }

        }
    }
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        go();
    }



}
