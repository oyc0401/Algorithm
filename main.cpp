
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>


using namespace std;


int main() {

    stack<int> sta;
    int a;
    cin >> a;
    for (int i = 0; i < a; ++i) {
        string message;

        cin >> message;

        if (message == "push") {
            int number;
            cin >> number;
            sta.push(number);
        } else if (message == "pop") {
            if(sta.empty()){
                cout<<"-1"<<"\n";
            }else{
                cout << sta.top() << "\n";
                sta.pop();
            }

        } else if (message == "size") {
            cout << sta.size() << "\n";
        } else if (message == "empty") {
            cout << sta.empty() << "\n";
        } else if (message == "top") {
            if(sta.empty()){
                cout<<"-1"<<"\n";
            }else{
                cout << sta.top() << "\n";
            }
        }

    }


    return 0;
}

