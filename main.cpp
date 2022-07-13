
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>


using namespace std;

bool isFan(string text){
    int size=text.size();
    int half=size/2;

    for (int i = 0; i < half; ++i) {
        if(text[i]!=text[size-1-i]){
            return false;
        }

    }
    return true;
}

int main() {
    string text;
    cin >> text;


    while (text!="0"){
       if(isFan(text)){
           cout<<"yes"<<endl;
       }else{
           cout<<"no"<<endl;
       }
        cin >> text;
    }
    
    return 0;
}

