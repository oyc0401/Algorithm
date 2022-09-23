#include <iostream>

#include <algorithm>

#include <vector>
#include <cmath>
#include <map>
#include <sstream>



using namespace std;

vector<string> split(string text, char div) {
    istringstream ss(text);
    string stringBuffer;
    vector<string> vec;
    vec.clear();

    // 자르기
    while (getline(ss, stringBuffer, div)) {
        vec.push_back(stringBuffer);
    }
    return vec;
}

int minute(string time) {
    vector<string> v = split(time, ':');
    int hour = stoi(v[0]);
    int min = stoi(v[1]);
    return hour * 60 + min;

}

class Car {
public:
    void setLast() {
        if (in.empty()) {

        } else if (out.empty()) {
            out.push_back(minute("23:59"));
        } else if (in.size() == out.size() + 1) {
            out.push_back(minute("23:59"));
        }
    }

    void setAll() {
        for (int n: in) {
            all += -n;
        }
        for (int n: out) {
            all += n;
        }
    }

    int getPrice(int a, int b, int c, int d) {
        setAll();

        if (all - a < 0) {
            return b;
        } else {
            double div = all - a;
            div /= c;

            int val = b + ceil(div) * d;
            return val;
        }

    }

    string name;
    vector<int> in;
    vector<int> out;
    long long int all = 0;
};

bool compareName(const Car &b1, const Car &b2) {
    // 낮은거 순
    //cout<<b1.in[0]<<", "<<b2.in[0]<<endl;
    return b1.name < b2.name;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, Car> myMap;
    int a, b, c, d;


    a = fees[0];
    b = fees[1];
    c = fees[2];
    d = fees[3];


    for (string message: records) {
        vector<string> sp;
        sp = split(message, ' ');
        string time = sp[0];
        string number = sp[1];
        string inout = sp[2];

        int min = minute(time);
        if (inout == "IN") {
            myMap[number].in.push_back(min);
            myMap[number].name = number;
        } else if (inout == "OUT") {
            myMap[number].out.push_back(min);
            myMap[number].name = number;
        }
    }

    vector<Car> vec;

    for (pair<string, Car> pa: myMap) {
        pa.second.setLast();
        vec.push_back(pa.second);
    }
    std::sort(vec.begin(), vec.end(), compareName);

    vector<int> answer;
    for (Car car: vec) {

        int price = car.getPrice(a, b, c, d);
        //cout << c.name << ", " << c.all << endl;
        answer.push_back(price);
    }


    return answer;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN",
                              "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

//    vector<int> fees = {120, 0, 60, 591};
//    vector<string> records = {"16:00 3961 IN",
//                              "16:00 0202 IN",
//                              "18:00 3961 OUT",
//                              "18:00 0202 OUT",
//                              "23:58 3961 IN"};

//    vector<int> fees = {1, 461, 1, 10};
//    vector<string> records = {"00:00 1234 IN"};


   // vector<int> sol = solution(fees, records);
    vector<int> sol = solution(
            {180, 5000, 10, 600},
            {"05:34 5961 IN", "06:34 5961 OUT", "07:34 5961 IN", "08:34 5961 OUT", "09:34 5961 IN", "10:34 5961 OUT", "11:34 5961 IN", "12:34 5961 OUT"}
    );
    for (int n: sol) {
        cout << n << endl;
    }

    cout<<stoi("09");


}
// 437674 3

// 859156 3