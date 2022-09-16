#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;
// 하루는 24 * 60 = 1440분, int 범위 안
int calMin(string s, string e) {
    // cout << s << ' ' << e << '\n';
    int sm = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    int em = stoi(e.substr(0, 2)) * 60 + stoi(e.substr(3));
    // cout << em - sm << '\n';
    return em - sm;
}
int calFee(vector<string> &rec, int t, int f, float t2, int f2) {
    int all_time = 0; // 누적 주차 시간
    for (int i = 0; i < (rec.size() + 1) / 2; i++) {
        if (rec.size() < (i + 1) * 2) {
            all_time += calMin(rec[i * 2], "23:59");
        } else {
            all_time += calMin(rec[i * 2], rec[i * 2 + 1]);
        }
    }
    if (all_time <= t) { // 기본 시간 이하
        return f;
    }
    // cout << f + ceil((all_time - t) / t2) * f2 << '\n';
    return f + ceil((all_time - t) / t2) * f2;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    // 차 id 부여
    map<string, int> car_id;
    string time, num_str, info;
    int i, id = 1;
    for (i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        ss >> time >> num_str >> info;
        if (car_id[num_str] == 0)
            car_id[num_str] = id++;
    }

    // 입차 출차 정보 정리
    vector<vector<string>> rec(id, vector<string>());
    for (i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        ss >> time >> num_str >> info;
        rec[car_id[num_str]].push_back(time);
    }

    // 시간 계산
    vector<int> ans;
    for (auto [num, c_id]: car_id) {
        // cout << "차번호, id: " << num << ' ' << c_id << '\n';
        ans.push_back(calFee(rec[c_id], fees[0], fees[1], fees[2], fees[3]));
    }
    return ans;
}