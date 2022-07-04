#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

vector<int> ropes;

// 몇개로 나뉘는지 함수
int hownuch(int size) {
    int sum = 0;
    for (int rope: ropes) {
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


int getAnswer(int size,int N) {
    int po=N;
    while (po==N){
        size++;
      N= hownuch(size);
      // cout<<N<<endl;
    }

    return size-1;
}

int hownuchNaMuZi(int size) {
    int small = 10000000;

    for (int rope: ropes) {
        int namuzi = rope % size;

        int count = rope / size;
        if (count > 0) {

            int dsa = namuzi / count;
            if (small > dsa) {
                small = dsa;
            }
        }

        // cout << setw(6) << rope << ": " << size << " * " << rope / size << " + " << namuzi << endl;
    }

    // cout << min << ", " << max << endl;

    return small;

}

int getsize(long long int sum, int N) {
    int current = sum / N;
    int num = hownuch(current);
    //cout << current << ", " << num << endl;

    while (num != N) {
        //cout << num << endl;
        int divide = current * num / N;
        if (divide == current) {
            //cout << "나눌 수 없음" << endl;
            break;
        }

        current = divide;
        //cout << "cm 조정 " << current << ", " << N << ", " << num << endl;

        num = hownuch(current);
        //cout << current << ", " << num << endl;
    }

    return current;
}


int main() {

    int K, N;
    cin >> K >> N;


    long long int sum = 0;
    // 배열에 넣기
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        ropes.push_back(a);
        sum += a;
    }
    // 구하기

    int current = getsize(sum, N);

    int plus = hownuchNaMuZi(current);
//    cout << plus << endl;
//
//cout << current + plus;
    int an=getAnswer(current,N);
    cout<<an;




    return 0;
}

