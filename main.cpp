
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

int INF = 100000000;

class Node {
public:
    Node(int n, int w) : node(n), weight(w) {}

    int node;
    int weight;
};

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count, lenght;
    cin >> count >> lenght;

    // arr
    int **arr = new int *[count];
    for (int i = 0; i < count; ++i) {
        arr[i] = new int[count];
    }

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            arr[i][j] = INF;
        }
        arr[i][i] = 0;
    }

    // graph
    int **graph = new int *[count];
    for (int i = 0; i < count; ++i) {
        graph[i] = new int[count];
    }

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            graph[i][j] = 0;
        }
    }


    for (int i = 0; i < lenght; ++i) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        if (graph[a][b] == 0) {
            graph[a][b] = weight;
        } else if (graph[a][b] > weight) {
            graph[a][b] = weight;
        }
        if (arr[a][b] > weight) {
            arr[a][b] = weight;
        }


    }


//    cout << "<노드>\n";
//    for (int i = 0; i < count; ++i) {
//        for (int j = 0; j < count; ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "<가중치>\n";
//    for (int i = 0; i < count; ++i) {
//        for (int j = 0; j < count; ++j) {
//            if (arr[i][j] == INF) {
//                cout << "INF" << " ";
//            } else {
//                cout << arr[i][j] << " ";
//            }
//        }
//        cout << endl;
//    }
//
//    cout << endl;


    for (int focusNode = 0; focusNode < count; ++focusNode) {
        for (int k = 0; k < count; ++k) {
            for (int next = 0; next < count; ++next) {

                // focusNode = 1, k = 3, next = 2
                // 3 -> 1 로의 가중치 + 1 -> 2 로의 가중치가
                int sum = arr[k][focusNode] + arr[focusNode][next];
                // 3 -> 2 로의 가중치 보다 작으면
                if (sum < arr[k][next]) {

//                    cout << "가중치: " << k << "->" << focusNode << "->" << next << " = " << sum << " <-> "
//                         << arr[k][next] << endl;
                    arr[k][next] = sum;
//                    for (int i = 0; i < count; ++i) {
//                        for (int j = 0; j < count; ++j) {
//                            if (arr[i][j] == INF) {
//                                cout << "INF" << " ";
//                            } else {
//                                cout << arr[i][j] << " ";
//                            }
//                        }
//                        cout << endl;
//                    }
//                    cout << endl;
                } else {
//                    cout << "작지않다: " << k << "->" << focusNode << "->" << next << " = " << sum << " <-> "
//                         << arr[k][next] << endl;
                }


            }


        }

    }

//    cout << "<노드>\n";
//    for (int i = 0; i < count; ++i) {
//        for (int j = 0; j < count; ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "<가중치>\n";
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (arr[i][j] == INF) {
                cout << "0" << " ";
            } else {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


