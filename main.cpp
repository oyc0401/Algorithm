
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>


using namespace std;


int main() {

    queue<int> que;
    int a;
    cin >> a;
    for (int i = 0; i < a; ++i) {
        string message;

        cin >> message;

        if (message == "push") {
            int number;
            cin >> number;
            que.push(number);
        } else if (message == "pop") {
            if(que.empty()){
                cout<<"-1"<<"\n";
            }else{
                cout << que.front() << "\n";
                que.pop();
            }

        } else if (message == "size") {
            cout << que.size() << "\n";
        } else if (message == "empty") {
            cout << que.empty() << "\n";
        } else if (message == "front") {
            if(que.empty()){
                cout<<"-1"<<"\n";
            }else{
                cout << que.front() << "\n";
            }
        }else if (message == "back") {
            if(que.empty()){
                cout<<"-1"<<"\n";
            }else{
                cout << que.back() << "\n";
            }
        }

    }


    return 0;
}

