#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int SIZE = 50001;
const int INF = 1e9;

bool isGate(int a, vector<int> &g) {
    for (int i: g) {
        if (i == a) {
            return true;
        }
    } return false;
}
bool isSummit(int a, vector<int> &s) {
    for (int i: s) {
        if (i == a) {
            return true;
        }
    } return false;
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    int its[SIZE];
    fill_n(its, SIZE, 1e9);
    // 그래프 생성
    vector<vector<ci> > g(n + 1);
    for (int i = 0; i < paths.size(); i++) {
        bool f_g = isGate(paths[i][0], gates), b_s = isSummit(paths[i][1], summits),
        f_s = isSummit(paths[i][0], summits), b_g = isGate(paths[i][1], gates);
        if (f_g && b_g || f_s && b_s) {
            continue;
        }
        if (f_g || b_s) { // -> 단방향만
            g[paths[i][0]].push_back({paths[i][1], paths[i][2]});
            continue;
        }
        if (b_g || f_s) { // <- 단방향만
            g[paths[i][1]].push_back({paths[i][0], paths[i][2]});
            continue;
        }
        // 양방향
        g[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        g[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }
    priority_queue<ci, vector<ci>, greater<>> pq; // 누적된 최소 intensity, 정점까지의
    for (int a: gates) {
        its[a] = 0;
        pq.push({0, a});
    }
    while (!pq.empty()) {
        auto [i, cur] = pq.top(); pq.pop(); // 1번까지 거리 0
        for (auto [nxt, nxt_i]: g[cur]) { // 1번에서 2번까지는 3
            if (max(i, nxt_i) < its[nxt]) {
                its[nxt] = max(i, nxt_i);
                pq.push({its[nxt], nxt});
            }
        }
    }
    // 정답 출력
    vector<int> ans = {0, INF};
    for (int s: summits) {
        if (its[s] < ans[1]) {
            ans[1] = its[s];
            ans[0] = s;
        } else if (its[s] == ans[1]) {
            ans[0] = min(ans[0], s);
        }
    }
    return ans;
}