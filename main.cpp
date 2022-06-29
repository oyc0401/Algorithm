
#include <iostream>


using namespace std;

int main() {
    int x,y,maxX,maxY;
    cin>>x>>y>>maxX>>maxY;

    int small=x;

    if(small>y){
        small=y;
    }
    if(small>maxX-x){
        small=maxX-x;
    }
    if(small>maxY-y){
        small=maxY-y;
    }

    cout<<small;



    return 0;
}

