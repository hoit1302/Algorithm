#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tpl(int n, int w, vector<vector<int>> &graph, vector<int> &indegree, vector<int> &con) {
    queue<int> q;
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            dp[i] = con[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: graph[cur]) {
            indegree[nxt]--;
            dp[nxt] = max(dp[nxt], con[nxt] + dp[cur]);
            if (!indegree[nxt]) {
                if (nxt == w) { // 가지치기
                    return dp[w];
                }
                q.push(nxt);
            }
        }
    }
    return dp[w];
}
int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t, n, k, x, y, w;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<vector<int>> graph(n+1, vector<int>());
        vector<int> con(n+1), indegree(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> con[i];
        }
        while (k--) {
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;
        cout << tpl(n, w, graph, indegree, con) << '\n';
    }
}