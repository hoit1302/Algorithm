#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
 * 특정 거리의 도시 찾기 [#](https://www.acmicpc.net/problem/18352)
 * 해당 정점에 대해서 더 탐색해야할 때(큐에 삽입)/탐색하지 않아도 될 때를 구분하여 구현한다.
 */
typedef pair<int, int> ci;
int main() {
    int n, m, k, x, a, b;
    cin >> n >> m >> k >> x;
    vector<vector<int> > graph(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    queue<int> q; // 도시, 최단 거리
    vector<int> dis(n + 1, -1), ans;
    q.push(x);
    dis[x] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : graph[cur]) {
            if (dis[nxt] != -1) continue;
            dis[nxt] = dis[cur] + 1;
            // 가지치기 1: 갱신된 최단 거리가 k보다 작을 때만 다음 정점에 대해서 탐색하도록 함.
            if (dis[nxt] < k) {
                q.push(nxt);
            }
            // 가지치기 2: 갱신된 거리가 k와 같다면 정답에 저장함.
            if (dis[nxt] == k) {
                ans.push_back(nxt);
            }
        }
    }
    // 출력
    if (ans.empty()) {
        cout << "-1\n";
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int _ : ans) {
        cout << _ << '\n';
    }
}