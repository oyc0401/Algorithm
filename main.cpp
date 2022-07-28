
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

template<class T>
class dual_priority_queue {
public:
    void push(T num) {
        queMin.push(num);
        queMax.push(num);
        count[num]++;
    }

    void pop_min() {
        cleanMin();
        assert(!queMin.empty());

        count[queMin.top()]--;
        queMin.pop();
    }

    void pop_max() {
        cleanMax();
        assert(!queMin.empty());

        count[queMax.top()]--;
        queMax.pop();
    }

    T min() {
        return queMin.top();
    }

    T max() {
        return queMax.top();
    }

    bool empty() {
        cleanMin();
        cleanMax();

        if (queMin.empty() || queMax.empty())
            return true;

        return false;
    }


private:
    priority_queue<T, vector<T>, greater<>> queMin;
    priority_queue<T, vector<T>, less<>> queMax;
    map<T, int> count;

    void cleanMin() {
        while (!queMin.empty() && count[queMin.top()] == 0) {
            // 맨 위가 없는 번호이면
            queMin.pop();
        }
    }

    void cleanMax() {
        while (!queMax.empty() && count[queMax.top()] == 0) {
            // 맨 위가 없는 번호이면
            queMax.pop();
        }
    }

};


void realPlay() {
    int ind;
    cin >> ind;
    dual_priority_queue<int> myque;

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


