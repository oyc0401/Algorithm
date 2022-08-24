#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


int boon(int number) {


    int sum = 0;

    int div = 10;
    for (int i = 0; i < 7; ++i) {
        int n = number % div;
        sum = sum + (n / (div / 10));
        div *= 10;
       // cout << sum << endl;
    }
    return sum;

}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int arr[1010001];
    for (int i = 1; i <= 1000000; ++i) {
        arr[i]=0;
    }

    for (int i = 1; i <= 1000000; ++i) {
        int n=i+boon(i);
        if(arr[n]==0){
            arr[n]=i;
        }

    }

//    for (int i = 1; i <= 1000000; ++i) {
//        cout << i << ": " << arr[i] << '\n';
//    }

int num;
    cin>>num;
    cout<<arr[num];

}
