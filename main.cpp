
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

//1
//7
//I 16
//I -5643
//D -1
//D 1
//D 1
//I 123
//D -1

class dual_priority_queue {
public:
    void push(int num) {
        queMin.push(num);
        queMax.push(num);
        if(count.count(num)==0){
            count[num]=1;
        }else{
            count[num]++;
        }


    }

    void pop_min() {
        resetMin();
        resetMax();

        // 배열 비어있으면 오류남
        count[queMin.top()]--;
        queMin.pop();

    }

    void pop_max() {
        resetMin();
        resetMax();

        count[queMax.top()]--;
        queMax.pop();
    }

    int min() {
        return queMin.top();
    }

    int max() {
        return queMax.top();
    }

    bool empty() {

        resetMin();
        resetMax();
        if (queMin.empty() || queMax.empty()) {
            return true;
        } else {
            return false;
        }
    }


private:
    priority_queue<int, vector<int>, greater<int>> queMin;
    priority_queue<int, vector<int>, less<int>> queMax;
    map<int, int> count;

    void resetMin() {
        while (!queMin.empty() && count[queMin.top()] <= 0) {
            // 맨 위가 없는 번호이면
            queMin.pop();
        }
    }

    void resetMax() {
        while (!queMax.empty() && count[queMax.top()] <= 0) {
            // 맨 위가 없는 번호이면
            queMax.pop();
        }
    }

};

void realPlay() {
    int ind;
    cin >> ind;
    dual_priority_queue myque;

    for (int i = 0; i < ind; ++i) {
        char order;
        int num;
        cin >> order >> num;

        if (order == 'I') {
            myque.push(num);

        } else if (order == 'D') {
            if (num == -1) {
                if (!myque.empty()) {
                    myque.pop_min();
                }
            } else if (num == 1) {
                if (!myque.empty()) {
                    myque.pop_max();
                }
            }
        }

    }
    // 프린트
    if (myque.empty()) {
        cout << "EMPTY\n";
    } else {
        cout << myque.max() << " " << myque.min() << "\n";
    }

}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int co;
    cin >> co;
    for (int i = 0; i < co; ++i) {
        realPlay();
    }


    return 0;
}


