
#include <iostream>
#include <map>
#include <iomanip>
#include "vector"

using namespace std;

int main() {
    int num;
    cin >> num;

    for(int i=1;i<=num;i++){
        for(int k=1;k<=i;k++){
            cout<<"*";
        }
        cout<<endl;
    }



    return 0;
}

