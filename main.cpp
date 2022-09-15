#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <cassert>


using namespace std;

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

int a,b;
cin>>a>>b;

map<string,string> myMap;

    for (int i = 0; i < a; ++i) {

        string email,password;
        cin>>email>>password;

        myMap[email]=password;
    }

    for (int i = 0; i < b; ++i) {
        string email;
        cin>>email;
        cout<<myMap[email]<<'\n';
    }


}
