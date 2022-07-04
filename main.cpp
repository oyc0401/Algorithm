
#include <iostream>
#include <vector>


using namespace std;

vector<int> ropes;

// 몇개로 나뉘는지 함수
int hownuch (int size) {
    int sum = 0;
    for (int rope: ropes) {
        sum += rope / size;
    }
    // cout << size << "cm" << ": " << sum << "개" << endl;
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

int hownuchNaMuZi(int size) {
    int max = 0;
    int min = 10000000;

    for (int rope: ropes) {
        int namuzi = rope % size;
        if (min > namuzi) {
            min = namuzi;
            max = rope / size;
        }
       // cout << rope << ": " << size << " * " << rope / size << " + " << namuzi << endl;
    }


    return min / max;

}


int main() {


    int K, N;
    cin >> K >> N;


    int big = 0;
    int min = 1;

    // 배열에 넣기
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        ropes.push_back(a);
        if (big < a) {
            big = a;
        }
    }

    // 구하기
    long long int middle = (big + min) / 2;

    int num = hownuch( middle);

    while (num != N) {

        if (num < N) {
            big = middle;
        } else if (num > N) {
            min = middle;
        } else {
        }

        if (middle == (big + min) / 2) {
            break;
        }
        middle = (big + min) / 2;
        //cout << min << ", " << middle << ", " << big << endl;
        num = hownuch( middle);
        //cout << current << ", " << num << endl;
    }

    int plus = hownuchNaMuZi(middle);

    cout << middle + plus;


    return 0;
}

