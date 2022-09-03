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



vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> count;
    vector<string> bad_list;
    map<string, int> mail;


    // 중복 제거
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(),report.end()),report.end());

    for (string id: report) {
        vector<string> v = split(id, ' ');
        count[v[1]]++;
    }


    for (pair<string,int> pa:count) {
        if(pa.second>=k){
            bad_list.push_back(pa.first);
        }
    }

    for (string id: report) {
        vector<string> v = split(id, ' ');

        for (string bad:bad_list) {
            if(bad==v[1]){
                mail[v[0]]++;
            }
        }
    }

    for (string id:id_list) {
        answer.push_back(mail[id]);
    }




    return answer;
}

// 1초: 1억번
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> id_list{"muzi", "frodo", "apeach", "neo"};
    vector<string> report{"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    int k = 2;
    vector<int> vec = solution(id_list, report, k);
    for (int n: vec) {
        cout << n << " ";
    }



}
// 437674 3

// 859156 3