
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>


using namespace std;

bool ff[50][50];

int getHow(int a, int b) {
    int white = 0;
    int black = 0;

    for (int i = 0; i < 8; ++i) {
        for (int k = 0; k < 8; ++k) {
           // cout << i + a << k + b;
            int A=i+a;
            int B=k+b;

            if (i % 2 == 0) {
                // 첫칸이 흰색
                if (k % 2 == 0) {
                    // 흰색칸
                    if(ff[A][B]){
                        white++;
                    }else{
                        black++;
                    }
                } else {
                    // 검정색칸
                    if(ff[A][B]){
                        black++;
                    }else{
                        white++;
                    }
                }
            } else {
                if (k % 2 == 0) {
                    // 검정색칸
                    if(ff[A][B]){
                        black++;
                    }else{
                        white++;
                    }
                } else {
                    // 흰색칸
                    if(ff[A][B]){
                        white++;
                    }else{
                        black++;
                    }
                }
            }
        }
        //cout << endl;
    }

   // cout<<"흰"<<white<<endl;
    //cout<<"검"<<black<<endl;

    if(white>black){
        return black;
    }else{
        return white;
    }
}


int main() {

    queue<int> que;
    int a, b;
    cin >> a >> b;


    for (int i = 0; i < a; ++i) {
        string line;
        cin >> line;
        for (int k = 0; k < b; ++k) {
            if (line[k] == 'W') {
                ff[i][k] = true;
            } else if (line[k] == 'B') {
                ff[i][k] = false;
            }
        }
    }


   //int how = getHow(0, 0);
    //cout << how;
    int min=64;

    for (int i = 0; i <= a-8; ++i) {
        for (int k = 0; k <= b-8; ++k) {
            //cout<<i<<k<<endl;
            int how = getHow(i, k);
            if(min>how){
                min=how;
            }

        }
    }
    cout<<min;


//    for (int i = 0; i < a; ++i) {
//        for (int k = 0; k < b; ++k) {
//            cout<< ff[i][k];
//        }
//        cout<<endl;
//    }




    return 0;
}

