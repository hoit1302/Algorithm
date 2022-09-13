#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
typedef long long ll;
ll its[50001];
vector<vector<ci>> g;
vector<int> sms, ans;
bool isSubmit(int cur) {
    for (int a: sms) {
        if (cur == a) return true;
    } return false;
}
void dfs(int cur, int it) {
    if (isSubmit(cur)) { // 종료 조건
        if (ans.empty()) {
            ans = {cur, it};
            return;
        }
        if (it < ans[1]) {
            ans = {cur, it};
            return;
        }
        if (it == ans[1]) {
            ans[0] = min(ans[0], cur);
        }
        return;
    }

    for (auto [nxt, n_cst]: g[cur]) {
        if (its[nxt] != -1) continue; // 방문할 수 없는 경우: 이미 방문한 경우
        // 방문함
        its[nxt] += n_cst;
        dfs(nxt, max(n_cst, it));
        its[nxt] -= n_cst;
    }
}

// 1차 시도, 35분, DFS로 풀이, 45.2점. 반절 이상은 TLE
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    sms.assign(summits.begin(), summits.end());
    g.assign(n + 1, vector<ci>());
    for (int i = 0; i < paths.size(); i++) {
        g[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        g[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }

    for (int a: gates) {
        fill_n(its, 50001, -1);
        its[a] = 0;
        dfs(a, 0);
    }
    return ans;
}