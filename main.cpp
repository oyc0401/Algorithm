#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <stack>

using namespace std;


template<typename T>
class LinkedListStack {
private:
    struct Node {
        T data;
        Node *next;

        Node(T d) : data(d), next(nullptr) {}
    };

    Node *topNode;
    int _size;

public:
    LinkedListStack() : topNode(nullptr) {
        _size = 0;
    }

    void push(T data) {
        Node *newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
        _size++;
    }

    void pop() {
        if (topNode == nullptr) {
            std::cerr << "Stack underflow\n";
            return;
        }

        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        _size--;
    }

    int size() { return _size; }

    T top() const {
        if (topNode == nullptr) {
            std::cerr << "Stack underflow\n";
            return T();
        }

        return topNode->data;
    }

    bool empty() const {
        return topNode == nullptr;
    }

    ~LinkedListStack() {
        while (topNode != nullptr) {
            Node *temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};


LinkedListStack<pair<int, int>> myVec[1000001];


int myVecSize = 0;

int lastIdx(int target) {
    int size = myVecSize;
    int left = 0;
    int right = size - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

//        cout << left << ", " << mid << ", " << right << endl;

        int midObject = myVec[mid].top().second;
        if (midObject > target) {
            // 다운
            right = mid - 1;
        } else if (midObject < target) {
            // 업
            left = mid + 1;
        } else {
            left = mid;
            break;
        }
    }

    return left;
}
// 0 9
// 1 3 6 8 10 13 17 18 20

int minNum = -2'000'000'000;



// 1000000000000000000
// 1초: 1억번
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);


    int idx;
    cin >> idx;
//    queue<int> que;
    vector<int> vec;

    myVec[0].push(make_pair(-1, minNum));
    myVecSize++;

    for (int i = 0; i < idx; ++i) {
        int a;
        cin >> a;
        vec.push_back(a);
    }


    int saveIdx = 1;
//    vector<int> saveVec;
    for (int i = 0; i < vec.size(); ++i) {

        // cout<<que.front()<<":\n";

        int cur = vec[i];
        int last = lastIdx(cur);

        if (myVecSize <= last) {
            myVec[myVecSize].push(make_pair(i, cur));
            myVecSize++;



            saveIdx = i;
        } else {
            myVec[last].push(make_pair(i, cur));

        }




//
        /// print
        for (int k = 0; k < myVecSize; ++k) {
            cout << "(" << k << ", " << myVec[k].top().second << ", " << myVec[k].size() << ") ";
        }
        cout << endl;

    }


//    cout << sizeof myVec[3] << endl;
    cout << myVecSize - 1 << endl;


    stack<int> printStack;

    for (int i = myVecSize - 1; i > 0; --i) {

        while (myVec[i].top().first > saveIdx) {
            myVec[i].pop();
        }
        saveIdx = myVec[i].top().first;
        if (myVec[i].top().second != minNum) {
            printStack.push(myVec[i].top().second);
        }
    }

    while (!printStack.empty()) {
        cout << printStack.top() << " ";
        printStack.pop();
    }


}

//14
//1 2 10 10 11 4 99 13 14 5 6 7 3 3

/// 3 6 5 7 8 3 2 7 9 1 5 7 4 2 9 8 2 3 4 8 7 9

