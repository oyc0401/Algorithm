
#include <iostream>

#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>


using namespace std;

// 1초: 1억번
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);


    int index, number;
    cin >> index >> number;

    vector<int> vec;
    int max = 0;


    for (int i = 0; i < index; ++i) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    for (int i = 0; i < vec.size(); ++i) {
        int first = vec[i];
        for (int j = i+1; j < vec.size(); ++j) {
            int second = vec[j];
            for (int k = j+1; k < vec.size(); ++k) {
                int third = vec[k];
                int sum = first + second + third;
                if (sum <= number) {
                    //cout << first << ", " << second << ", " << third<<endl;
                    max = sum > max ? sum : max;
                }
            }
        }
    }

    cout << max;

    return 0;
}
