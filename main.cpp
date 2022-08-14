#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

// B+C
// A+B+C
//A+BCx
string backPlus(string text) {
    string val = "";
    stack<char> sign;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == '+' || text[i] == '-') {
            sign.push(text[i]);
        } else if (text[i] == '(' || text[i] == ')') {
            val += '.';
        } else {
            val += text[i];
        }
    }

    while (!sign.empty()) {
        if (sign.top() == '+') {
            val += 'p';
        } else if (sign.top() == '-') {
            val += 'm';
        }
        sign.pop();
    }

    return val;
}


string backTime(string text) {
    string val = "";
    stack<char> sign;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == '*' || text[i] == '/') {
            sign.push(text[i]);
        } else if (text[i] == '(' || text[i] == ')') {
            val += '.';
        } else {
            val += text[i];
        }
    }

    while (!sign.empty()) {
        if (sign.top() == '*') {
            val += 'x';
        } else if (sign.top() == '/') {
            val += 'd';
        }
        sign.pop();
    }

    return val;
}




//string brackets(string text) {
//
//    int lastS = 0;
//    bool findMulti = false;
//    stack<int> sta;
//    for (int i = 0; i < text.size(); ++i) {
//       // cout<<text<<endl;
//        if (text[i] == '*' || text[i] == '/') {
////            cout<<i<<" ";
//            findMulti = true;
//        }
//
//        if (text[i] == '(') {
//            sta.push(i);
//        } else if (text[i] == ')') {
//            sta.pop();
//        }
//
//
//        if (text[i] == '+' || text[i] == '-') {
//            if (sta.empty()&&findMulti) {
//                text.insert(lastS , "(");
//                text.insert(i + 1, ")");
//                i += 2;
//                findMulti = false;
//            }
//            if (sta.empty()) {
//                lastS = i+1;
//            }
//        }
//
//    }
//
//    if (findMulti) {
//        text.insert(lastS , "(");
//        text.insert(text.size(), ")");
//    }
//
//    text.insert(0 , "(");
//    text.insert(text.size(), ")");
//    return text;
//}
// +: p, -: m, *: x, /: d

// A+B*C*D/E-

//string brackets(string text) {
//
//    int lastS = 0;
//    bool findMulti = false;
//    stack<int> sta;
//    sta.push(0);
//    for (int i = 0; i < text.size(); ++i) {
//        if(text[i] == '+' || text[i] == '-'){
//            if(findMulti){
//                text.insert(sta.top(),"(");
//                text.insert(i+1,")");
//                i+=2;
//                lastS=i;
//            }else{
//                lastS=i;
//                findMulti= true;
//            }
//
//        }else if(text[i] == '*' || text[i] == '/'){
//
//            stack<int> stst;
//            if(text[i+1]=='('){
//                st
//            }
//            text.insert(lastS+1,"(");
//            text.insert(i+3,")");
//            i+=2;
//        }
//
//
//    }
//
//
//    return text;
//}


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text;
    cin >> text;


    stack<char> sta;


    for (int i = 0; i < text.size(); ++i) {
        //cout<<i<<" ";

        if (text[i] == '+' || text[i] == '-') {

            if (sta.empty() || sta.top() == '(') {
                sta.push(text[i]);
            } else {
                while (!sta.empty() && sta.top() != '(') {
                    cout << sta.top();
                    sta.pop();
                }
                sta.push(text[i]);
            }

        } else if (text[i] == '*' || text[i] == '/') {

            if (sta.empty() || sta.top() == '(') {
                sta.push(text[i]);
            } else {
                while (!sta.empty() && (sta.top() == '*' || sta.top() == '/')) {
                    cout << sta.top();
                    sta.pop();
                }
                sta.push(text[i]);
            }

        } else if (text[i] == '(') {

            sta.push('(');


        } else if (text[i] == ')') {

            while (!sta.empty() && sta.top() != '(') {
                cout << sta.top();
                sta.pop();
            }
            if (sta.top() == '(') {
                sta.pop();
            }

        } else {
            cout << text[i];
        }


    }
    while (!sta.empty()) {
        if (sta.top() != '(') {
            cout << sta.top();
        }
        sta.pop();
    }




//    text = brackets(text);
//    cout << text << endl;

    // (A*(B+C))
    // A*B+C

//    stack<int> sta;
//    int size = text.size();
//    for (int i = 0; i < size; ++i) {
//
//        if (text[i] == '(') {
//            sta.push(i);
//        } else if (text[i] == ')') {
//            int last = sta.top();
//            // 3~7
//            string start = text.substr(0, last);
//            string finish = text.substr(i + 1, size - i);
//            //cout<<start<<", "<<finish<<endl;
//
//            string st = text.substr(last, i - last + 1);
//            st = backPlus(st);
//            st = backTime(st);
//
//            text = start + st + finish;
//
//            cout << st << ", " << text << endl;
//            sta.pop();
//        }
//
//    }
//
//
//    for (int i = 0; i < text.size(); ++i) {
//        if (text[i] == '.') {
//
//        } else if (text[i] == 'p') {
//            cout << '+';
//        } else if (text[i] == 'm') {
//            cout << '-';
//        } else if (text[i] == 'x') {
//            cout << '*';
//        } else if (text[i] == 'd') {
//            cout << '/';
//        } else {
//            cout << text[i];
//        }
//
//    }


}
