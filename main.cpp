
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


    int a, b, c;

    cin >> a >> b >> c;
    while (a != 0 && b != 0 && c != 0) {
        int big;
        int first;
        int second;

        if(a<b){
            big=b;
            first=a;
        }else{
            big=a;
            first=b;
        }

        if(big<c){
            int t=big;
            big=c;
            second=t;
        }else{
            second=c;
        }


        if(big*big==first*first+second*second){
            cout<<"right\n";
        }else{
            cout<<"wrong\n";
        }
        cin >> a >> b >> c;
    }

    return 0;
}
