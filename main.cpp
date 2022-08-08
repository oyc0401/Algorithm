#include <iostream>
#include <map>
#include "vector"

using namespace std;

// 100,000 이하의 소인수 분해

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


void factorization(int number, map<int, int> &myMap, vector<int> &primes) {
    for (int prime: primes) {

        int sum = 0;
        for (long long int power = prime; power <= number; power *= prime) {
            // cout<<sum<<endl;
            sum += (number / power);
        }
        myMap[prime] = sum;
    }
}
// 937482931 264783641 100000

int main() {
    map<int, int> myMap;
    map<int, int> aMap;
    map<int, int> bMap;

    int num;
    cin >> num;
    vector<int> primes;

    setPrimeNumbers(501, primes);

    /// nCm = n! / ((n-m)! * m!)
    factorization(num, myMap, primes);

    int a = myMap[2];
    int b = myMap[5];
    int small = a < b ? a : b;
    cout << small;
//    factorization(n - m, aMap, primes);
//    factorization(m, bMap, primes);
//
//
//    // 분모 나누기
//    for (pair<int, int> itr: aMap) {
//        myMap[itr.first] -= itr.second;
//    }
//    for (pair<int, int> itr: bMap) {
//        myMap[itr.first] -= itr.second;
//    }
//
//    unsigned long long int num = 1;
//    //출력
//    for (pair<int, int> itr: myMap) {
//        for (int i = 0; i < itr.second; i++) {
//            num *= itr.first;
//        }
//
//        // cout << itr.first << ": " << itr.second << endl;
//    }

    //cout << num;


    return 0;
}

