#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

vector<int> vec;

long long int cut(int len) {

    long long int sum = 0;
    for (int n: vec) {
        int minus = n - len;
        if (minus > 0) {
            sum += minus;
        }
    }
    return sum;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ind, target;
    cin >> ind >> target;


    for (int i = 0; i < ind; ++i) {
        int a;
        cin >> a;
        vec.push_back(a);
    }


    int min = 0;
    int max = 2000000000;

     for (int i = 0; i < 40; ++i) {
   // while (min != max) {
        int half = (min + max) / 2;

      // cout << half << ", " << min << "~" << max << endl;

        long long int cutted = cut(half);


        if (cutted - target < 0) {
            ///cout << "다운: " << cutted << endl;
            max = half;
        } else {
           /// cout << "업: " << cutted << endl;
            min = half;
        }


    }


            if (cut(max) - target < 0) {
//                max = half;
//                break;
                cout << min;
                return 0;
            } else {
//                min = half;
//                break;
                cout << max;
                return 0;
            }



//    cout<<min<<endl;
//    cout << max;


}

//2 10000
//10001 20000
