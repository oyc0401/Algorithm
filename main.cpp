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
    string left, right;
};

map<string, Child> myMap;

void front(string id) {
    cout << id;
    if (myMap[id].left != ".") front(myMap[id].left);
    if (myMap[id].right != ".") front(myMap[id].right);

}

void middle(string id) {
    if (myMap[id].left != ".") middle(myMap[id].left);
    cout << id;
    if (myMap[id].right != ".") middle(myMap[id].right);

}

void back(string id) {
    if (myMap[id].left != ".") back(myMap[id].left);
    if (myMap[id].right != ".") back(myMap[id].right);
    cout << id;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx;
    cin >> idx;
    for (int i = 0; i < idx; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        Child child{};
        child.set(b, c);
        myMap[a] = child;
    }

    front("A");
    cout << endl;
    middle("A");
    cout << endl;
    back("A");


}
