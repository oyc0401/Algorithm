#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

bool is_prime(long long int number) {
    if(number==0||number==1){
        return false;
    }

    int sq = sqrt(number);
    for (int i = 2; i <= sq; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(int n, int k){
    stack<int> sta;

    while (n != 0) {
        int nod = n % k;
        sta.push(nod);
        n /= k;
    }


    vector<int> vec;
    while (!sta.empty()) {
     ///  cout<<sta.top();
        vec.push_back(sta.top());
        sta.pop();
    }
   ///cout<<endl;

    long long int num=0;
    vector<long long int> list;

    for (int ele: vec) {
///cout<<num<<endl;
        if (ele == 0) {
            list.push_back(num);
            num = 0;
        } else {
            num = num * 10 + ele;
        }
    }
   /// cout<<num<<endl;
   if(num!=0){
       list.push_back(num);
   }

    int sum = 0;
    for (long long int ele: list) {
      ///  cout << ele << endl;
        if (is_prime(ele)) {
            sum++;
        }

    }

    return sum;

}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);




    int n, k;
    cin >> n >> k;

    cout<<solution(n,k);

}
// 437674 3

// 859156 3

