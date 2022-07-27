
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;


// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int com, ind;
    cin >> com >> ind;

    bool *arr = new bool[com];
    vector<int> *list = new vector<int>[com];

    for (int i = 0; i < ind; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        list[a].push_back(b);
        list[b].push_back(a);
    }

//    for (int i = 0; i < com; ++i) {
//        cout << i << ": ";
//        for (int n: list[i]) {
//            cout << n << " ";
//        }
//        cout << endl;
//    }

    int sum=0;

    for (int i = 0; i < com; ++i) {
        queue<int> current;
        if(arr[i]== false){
            sum++;

            // 처음 감염은 i번 컴퓨터
            arr[i] = true;
            current.push(i);

            while (!current.empty()) {
                int front = current.front();
                vector<int> vec = list[front];
                ///cout << front << ": ";

                for (int num: vec) {
                    /// cout << num << " ";
                    if (arr[num] == false) {
                        arr[num] = true;
                        current.push(num);
                    }
                }
                ///cout << endl;
                current.pop();
            }
        }
    }



cout<<sum;
    return 0;
}


