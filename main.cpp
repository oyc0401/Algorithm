#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<string> vec;

    string text = "";


    while (text != ".") {
        stack<char> sta;
        getline(cin, text);
        //cout << text;
        if(text == "."){
            return 0;
        }

        bool yes= true;

        for (char ch: text) {

            if (ch == '(' || ch == '[') {
                sta.push(ch);
            }

            if (ch == ')') {
                if (!sta.empty() && sta.top() == '(') {
                    sta.pop();
                }else{
                    yes= false;
                }
            }else if (ch == ']') {
                if (!sta.empty() && sta.top() == '[') {
                    sta.pop();
                }else{
                    yes=false;
                }
            }


        }

        if(!sta.empty()){
            yes= false;
        }


        if(yes){
            cout<<"yes\n";
        } else{
            cout<<"no\n";
        }

    }


    for (string te: vec) {

    }
}



