#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> user_id; // 0. 유저에게 id 부여하기
    for (int i = 0; i < id_list.size(); i++) {
        user_id[id_list[i]] = i;
    }
    // 1. 중복된 신고를 제외하고 신고 정리하기
    vector<vector<int>> r_new(id_list.size(),  vector<int>());
    vector<int> r_cnt(id_list.size());
    string user, r_user;
    for (string users: report) {
        stringstream ss(users);
        ss >> user >> r_user;
        bool is_alr_ex = false;
        for (int r: r_new[user_id[user]]) {
            if (r == user_id[r_user]) {
                is_alr_ex = true;
                break;
            }
        }
        if (!is_alr_ex) {
            r_new[user_id[user]].push_back(user_id[r_user]);
            r_cnt[user_id[r_user]]++;
        }
    }

    /// 출력
    vector<int> ans(id_list.size(), 0);
    for (int i = 0; i < id_list.size(); i++) {
        for (int r: r_new[i]) {
            if (k <= r_cnt[r])
                ans[i]++;
        }
    }
    return ans;
}