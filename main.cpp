
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(8);

    int len, index;

    vector<int> vecX;
    vector<int> vecY;

    cin >> len >> index;

    for (int i = 0; i < len; ++i) {
        int a;
        cin >> a;
        vecX.push_back(a);
    }
    for (int i = 0; i < len; ++i) {
        int b;
        cin >> b;
        vecY.push_back(b);
    }

    vector<double> heL{0};
    vector<double> heR{0};

    double lastL = 0;
    double lastR = 0;

    for (int i = 0; i < len - 1; ++i) {
        long long int X = vecX[i + 1] - vecX[i];
        long long int Y = vecY[i + 1] - vecY[i];

        long long int XY = X * X + Y * Y;
        double dist = sqrt(XY);

        if (Y > 0) {
            heL.push_back(lastL + dist * 3);
            heR.push_back(lastR + dist);
            lastL += dist * 3;
            lastR += dist;
        } else if (Y == 0) {
            heL.push_back(lastL + dist * 2);
            heR.push_back(lastR + dist * 2);
            lastL += dist * 2;
            lastR += dist * 2;
        } else {
            heL.push_back(lastL + dist);
            heR.push_back(lastR + dist * 3);
            lastL += dist;
            lastR += dist * 3;
        }


    }

//    for (double d: heL) {
//        cout << d << " ";
//    }
//    cout << endl;
//    for (double d: heR) {
//        cout << d << " ";
//    }
//    cout << endl;



    for (int i = 0; i < index; ++i) {
        int start, finish;
        cin >> start >> finish;
        if (start < finish) {
            cout << heL[finish - 1] - heL[start - 1] << '\n';
        } else {
            cout << heR[start - 1] - heR[finish - 1] << '\n';
        }


    }

    return 0;
}


