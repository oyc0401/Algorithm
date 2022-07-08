
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>


using namespace std;


int main() {


    int a;
    cin >> a;


    for (int i = 0; i < a; ++i) {
        int left = 0;
        bool yes = true;

        string galho;
        cin >> galho;
        //cout << galho.size();
        for (int k = 0; k < galho.size(); ++k) {
            //cout<<galho[k]<<endl;
            if (galho[k] == '(') {
                left++;
            } else if (galho[k] == ')') {
                if (left > 0) {
                    left--;
                } else {
                    yes = false;
                    break;
                }
            }

        }
        if(left>0){
            yes= false;
        }
        if (yes) {
            cout << "YES"<<endl;
        } else {
            cout << "NO" << endl;
        }

    }


    return 0;
}

