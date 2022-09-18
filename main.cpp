#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <cassert>

using namespace std;

class Child {
public:
    void set(string left, string right) {
        this->left = left;
        this->right = right;
    }

//private:
    string left = ".", right = ".";
};

map<string, Child> myMap;

void front(string id) {
    cout << id << " ";
    if (myMap[id].left != ".") front(myMap[id].left);
    if (myMap[id].right != ".") front(myMap[id].right);

}

void middle(string id) {
    if (myMap[id].left != ".") middle(myMap[id].left);
    cout << id << " ";
    if (myMap[id].right != ".") middle(myMap[id].right);

}

void back(string id) {
    if (myMap[id].left != ".") back(myMap[id].left);
    if (myMap[id].right != ".") back(myMap[id].right);
    cout << id << " ";
}

pair<int, int> cal(int num) {
    if (num == 1) {
        return make_pair(0, 0);
    }

    int count = num;
    int sum = 0;

    int x = 1;
    for (int i = 1; i <= 6; ++i) {
        count -= x;
        ///cout << i << ", " << count << ", " << x << endl;

        if (count <= 0) {
            break;
        }
        sum += x / 2;
        x *= 2;
    }
    ///cout<<sum<<endl;

    int a = num - x + 1;

    int left;
    int right;
    if (a / (x / 2) == 0) {
        left = a;
        right = 0;
    } else {
        left = x / 2;
        right = a - (x / 2);
    }

    ///cout << left << ", " << right << endl;

    return make_pair(sum + left, sum + right);
}

string *arr;

void setTree(int front, int len) {
    pair<int, int> pa = cal(len);
    Child child = Child();
    if (pa.first != 0) {
        child.left = arr[front + pa.first - 1];
        setTree(front, pa.first);
    };
    if (pa.second != 0) {
        child.right = arr[front + pa.first + pa.second - 1];
        setTree(front + pa.first, pa.second);
    };
    myMap[arr[front + pa.first + pa.second]] = child;
    //cout<<arr[front + pa.first + pa.second]<<" "<<child.left<<" "<<child.right<<endl;




    // cout << arr[pa.first - 1] << ", " << arr[pa.first + pa.second - 1]<<endl;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index;
    cin >> index;
    arr = new string[index];
    string *fakearr = new string[index];

    for (int i = 0; i < index; ++i) {
        cin >> fakearr[i];
    }
    for (int i = 0; i < index; ++i) {
        cin >> arr[i];
    }



    setTree(0, index);


//    for (pair<string,Child> pai:myMap) {
//        cout<<pai.first<<" "<<pai.second.left<<" "<<pai.second.right<<endl;
//    }


    front(arr[index - 1]);

/// 지금 코드는 한 노드에 두명의 자식이 있는걸 계산하는데 문제는 그게 아니였음


//    int idx;
//    cin >> idx;
//    for (int i = 0; i < idx; ++i) {
//        string a, b, c;
//        cin >> a >> b >> c;
//        Child child{};
//        child.set(b, c);
//        myMap[a] = child;
//    }
//    front("1");
//    cout << endl;
//    middle("1");
//    cout << endl;
//    back("1");

}
// 3
// 2 3 1

// 20
// 16 17 8 18 19 9 4 20 10 11 5 2 12 13 6 14 15 7 3 1

// 20
// 1 2 3
// 2 4 5
// 3 6 7
// 4 8 9
// 5 10 11
// 6 12 13
// 7 14 15
// 8 16 17
// 9 18 19
// 10 20 .
// 11 . .
// 12 . .
// 13 . .
// 14 . .
// 15 . .
// 16 . .
// 17 . .
// 18 . .
// 19 . .
// 20 . .

