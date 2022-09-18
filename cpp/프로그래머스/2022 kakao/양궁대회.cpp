#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> ci;

bool isNeedChange(vector<int> &ans, vector<int> &lion_info) {
    for (int i = 10; i >= 0; i--) {
        if (ans[i] < lion_info[i]) {
            return true;
        } else if (ans[i] > lion_info[i]) {
            return false;
        }
    } return false;
}
vector<int> info;
int max_dif = 0;
vector<int> ans, lion_info(11, 0);
void select(int d, int n, int a_s, int l_s) {
    if (d == 10) {
        lion_info[d] = n;
        // cout << l_s - a_s  << ' ';
        // for (int a: lion_info) {
        //     cout << a << ", ";
        // } cout << '\n';
        if (max_dif < l_s - a_s) {
            ans.assign(lion_info.begin(), lion_info.end());
            max_dif = l_s - a_s;
            return;
        }
        if (max_dif && max_dif == l_s - a_s) {
            if (isNeedChange(ans, lion_info)) {
                ans.assign(lion_info.begin(), lion_info.end());
            }
        }
        lion_info[d] = 0;
        return;
    }

    if (info[d] + 1 <= n) { // 1 라이언이 점수를 가져가는 경우
        lion_info[d] = info[d] + 1;
        select(d + 1, n - info[d] - 1, a_s, l_s + 10 - d);
        lion_info[d] = 0;
    }
    // 2 라이언이 못 가져가는 경우
    if (info[d] == 0) { // 2-1 둘 다 0이라서 둘 다 점수를 못 가져가는 경우
        select(d + 1, n, a_s, l_s);
    } else { // 2-2 어피치가 점수를 가져가는 경우
        select(d + 1, n, a_s + 10 - d, l_s);
    }
}

// brute force
vector<int> solution(int n, vector<int> in) {
    info.assign(in.begin(), in.end());
    select(0, n, 0, 0);
    if (max_dif == 0) {
        return {-1};
    } return ans;
}