
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int MOD = 1234567891;
    int R = 31;
    int a;
    string text;
    unsigned long long int sum = 0;
    cin >> a >> text;

    for (int i = 0; i < a; ++i) {
        int data = text[i] - 'a' + 1;
        // cout << data << endl;
        unsigned long long pow = 1;
        for (int j = 0; j < i; ++j) {
            pow *= R;
            pow %= MOD;
        }
        unsigned long long int num = data * pow;
        //cout<<num<<endl;
        sum += num;
        sum %= MOD;
    }

    cout << sum;
    return 0;
}
