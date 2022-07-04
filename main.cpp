
#include <iostream>
#include <vector>


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

    int a,b;
    cin>>a>>b;

    vector<int> primes;
    setPrimeNumbers(b, primes);

    for (int pri:primes){
        if(pri>=a){
            cout<<pri<<"\n";
        }

    }

    return 0;
}

