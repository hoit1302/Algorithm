#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<vector<int> > graph;

vector<int> topolo(int n, vector<int> &indegree) {
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for (int nxt: graph[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    return ans;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    vector<int> indegree(n+1, 0);
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    vector<int> ans = topolo(n, indegree);
    for (int c: ans) {
        cout << c << ' ';
    }
}