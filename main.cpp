
#include <iostream>
#include <map>
#include <iomanip>
#include "vector"

using namespace std;

int main() {
    string str;

    cin >> str;
    map<char, int> map;

    for (char &c: str) {
        c = toupper(c);
    }

    for (char &c: str) {
        map[c]++;
    }

    int big = 0;
    char bigText;
    for (pair<char, int> pa: map) {
        if (big < pa.second) {
            big = pa.second;
            bigText=pa.first;
        }
    }

    int check=0;
    for (pair<char, int> pa: map) {
        if (big == pa.second) {
           check++;
        }
        if(check==2){
            cout<<"?";
            return 0;
        }
    }

    cout<<bigText;

    return 0;
}

