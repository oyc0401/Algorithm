
#include <iostream>
#include <map>
#include "vector"

using namespace std;

// 100,000 이하의 소인수 분해
void divide(int target, map<int, int> &map, vector<int> &primes) {
    int i = 0;
    while (target != 1 && i < primes.size()) {
        int num = primes[i];
        //cout << target << endl;
        while (target % num == 0) {
            target = target / num;
            map[num]++;
            //cout << num << endl;
        }
        i++;
    }
}

bool canDivide(map<int, int> &myMap, map<int, int> &Imap) {
    for (pair<int, int> itr: Imap) {
        if (myMap[itr.first] - itr.second < 0) {
            return false;
        }

    }
    return true;
}

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


void sethowmuch(int number, map<int, int> &myMap, vector<int> &primes) {
    for (int prime: primes) {

      int sum=0;
        for (long long int power = prime; power <= number; power *= prime) {
           // cout<<sum<<endl;
            sum+=(number/power);
        }
        myMap[prime]=sum;
    }
}
// 937482931 264783641 100000

int main() {
    map<int, int> myMap;
    map<int, int> aMap;
    map<int, int> bMap;

    int a, b, M;
    cin >> a >> b >> M;
    vector<int> primes;
    setPrimeNumbers(M, primes);
    //cout<<"Da332s"<<endl;
    // 팩토리얼 소인수 분해
    sethowmuch(a+b, myMap, primes);
    //cout<<"Das"<<endl;
    sethowmuch(a, aMap, primes);
    sethowmuch(b, bMap, primes);





    // 분모 나누기
    for (pair<int, int> itr: aMap) {
        myMap[itr.first] -= itr.second;
    }
    for (pair<int, int> itr: bMap) {
        myMap[itr.first] -= itr.second;
    }

    // 출력
//    for (pair<int, int> itr: myMap) {
//        cout << itr.first << ": " << itr.second << endl;
//    }

    bool isfind = false;

    for (int i = M; i >= 1; i--) {

        map<int, int> Imap;
        divide(i, Imap, primes);
        bool can = canDivide(myMap, Imap);

        if (can) {
            cout << i;
            //cout << "답: " << i << endl;
            isfind = true;
            break;
        }
    }

    if (!isfind) {
        cout << -1;
    }

    return 0;
}

