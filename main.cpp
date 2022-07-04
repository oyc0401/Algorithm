#include <iostream>
#include <vector>


using namespace std;

// 몇개로 나뉘는지 함수
long long int hownuch(vector<long long int> &ropes, long long int size) {
    long long int sum = 0;
    for (long long int rope: ropes) {
        sum += rope / size;
    }
    //cout << size << "cm" << ": " << sum << "개" << endl;
    return sum;
}

//4 300
//802
//743
//457
//539

// 4 13
// 802
// 743
// 457
// 539

long long int hownuchNaMuZi(vector<long long int> &ropes, long long int size) {
    long long int max = 0;
    long long int min = 10000000;

    for (int rope: ropes) {
        long long int namuzi = rope % size;
        if (min > namuzi) {
            min = namuzi;
            max = rope / size;
        }
        //cout << rope << ": "<<size<<" * "<<rope / size << " + " << namuzi << endl;
    }


    return min / max;

}


int main() {

    long long int K, N;
    cin >> K >> N;
    vector<long long int> ropes;

    long long int sum = 0;
    // 배열에 넣기
    for (long long int i = 0; i < K; i++) {
        long long int a;
        cin >> a;
        ropes.push_back(a);
        sum += a;
    }
    // 구하기

    long long int current = sum / N;
    long long int num = hownuch(ropes, current);
    //cout << current << ", " << num << endl;

    while (num != N) {
        //cout << num << endl;

        //cout << "cm 조정 " << current << ", " << N << ", " << num << endl;

        long long int divide = current * num / N;
        if (divide == current) {
            //cout << "나눌 수 없음" << endl;
            break;
        }
        current = divide;

        num = hownuch(ropes, current);
        //cout << current << ", " << num << endl;
    }

    long long int plus = hownuchNaMuZi(ropes, current);
    //cout << plus << endl;

    cout << current + plus;


    return 0;
}

