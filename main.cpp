
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>


using namespace std;


int main() {

    int a;
    vector<int> vec;

    cin>>a;

    for (int i = 0; i < a; ++i) {
        int number;
        cin >> number;
        vec.push_back(number);
    }


   std::sort(vec.begin(), vec.end());

    for (int num:vec) {
        cout << num << "\n";
    }


    return 0;
}
