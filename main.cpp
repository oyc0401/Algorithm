
#include <iostream>

#include <algorithm>
#include <set>
#include <deque>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    deque<int> deq;
    int a;
    cin >> a;
    for (int i = 0; i < a; ++i) {
        string message;

        cin >> message;

        if (message == "push_front") {
            int number;
            cin >> number;
            deq.push_front(number);
        } else if (message == "push_back") {
            int number;
            cin >> number;
            deq.push_back(number);
        } else if (message == "pop_front") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        } else if (message == "pop_back") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.back() << "\n";
                deq.pop_back();
            }
        } else if (message == "size") {
            cout << deq.size() << "\n";
        } else if (message == "empty") {
            cout << deq.empty() << "\n";
        } else if (message == "front") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.front() << "\n";
            }
        } else if (message == "back") {
            if (deq.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << deq.back() << "\n";
            }
        }

    }


    return 0;
}

