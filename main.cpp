
#include <iostream>
#include <map>
#include <iomanip>
#include "vector"

using namespace std;

int main() {
    string str;

    getline(cin,str);
    map<char, int> map;

    int sum=0;
    if(str[0]==' '){
        sum--;
    }
    if(str[str.length()-1]==' '){
        sum--;
    }


    for (char c: str) {
        if(c==' '){
            sum++;
        }
    }
    cout<<sum+1;






    return 0;
}

