
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>


using namespace std;


int main() {

    queue<int> que;
    int a;
    cin >> a;

    for (int i = 1; i <= a; ++i) {
        que.push(i);
    }

    for (int i = 1; i < a; ++i) {
        que.pop();
        int num=que.front();
        que.pop();
        que.push(num);
    }

    cout<<que.front();
    return 0;
}
