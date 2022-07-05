
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void setPrimeNumbers(int n, vector<int> &primes) {
    bool *isPrime = new bool[n + 1];// n까지 구해야하므로, n+1개를 동적할당

    //먼저 모든 배열을 true로 초기화
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);//해당수가 소수라면, 출력하고 해당수를 제외한 배수들을 모두 제외
            // cout << i << " ";
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {

    int a;
    cin >> a;
    vector<int> vec;
    int max = 0;

    for (int i = 0; i < a; ++i) {
        int ip;
        cin >> ip;
        vec.push_back(ip);
        if (max < ip) {
            max = ip;
        }
    }

    vector<int> primes;
    setPrimeNumbers(max, primes);

    int sum = 0;
    for (int num: vec) {

        if (find(primes.begin(), primes.end(), num) == primes.end()) {
            //cout << num << "은 찾을 수 없습니다.\n";
        } else {
            //cout << num << "는 존재하며 인덱스는 " << it - primes.begin() << " 입니다.\n";
            sum++;
        }

    }

    cout << sum;

    return 0;
}

