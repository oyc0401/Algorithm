
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>


using namespace std;

vector<string> vec[51];

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; ++i) {
        string text;
        cin >> text;

        int len = text.size();
        if (find(vec[len].begin(), vec[len].end(), text) == vec[len].end()) {
            vec[len].push_back(text);
        }


    }

    for (vector<string> vector: vec) {
        if (vector.size() > 0) {
            sort(vector.begin(), vector.end());
            for (string text: vector) {
                cout << text<<endl;
                //cout << text << ", ";
            }
           // cout << endl;
        }
    }




//
//    if ('i' < 'b') {
//        cout << "참";
//    } else {
//        cout << "거짓";
//    }


    return 0;
}

