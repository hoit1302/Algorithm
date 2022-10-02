#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;
const int INF = 1e9;
int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        // 입력
        int n, m, t, s, g, h, a, b, d, x;
        cin >> n >> m >> t >> s >> g>> h;
        vector<vector<ci>> graph(n + 1, vector<ci>());
        while (m--) {
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }
        vector<int> dest;
        for (int i = 0; i < t; i++) {
            cin >> x;
            dest.push_back(x);
        }

        // 계산
        int dist[2001][2];
        for (int i = 0; i < 2001; i++) {
            dist[i][0] = INF;
            dist[i][1] = 0; // false
        }
        priority_queue<ci, vector<ci>, greater<>> pq; // 누적 거리, to 정점
        dist[s][0] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [cost, cur] = pq.top(); pq.pop();
            if (dist[cur][0] < cost) continue;
            for (auto [nxt, nxt_cost]: graph[cur]) {
                if (dist[nxt][0] < dist[cur][0] + nxt_cost) continue;
                // cout << cur << "부터 " << nxt << "까지 " << dist[cur][0] + nxt_cost << '\n';
                if (dist[nxt][0] == dist[cur][0] + nxt_cost) {
                    if (dist[nxt][1]) continue; // 같은 거리이고 필수 도로를 거쳐서 왔음
                }
                // 더 짧은 경우, 같은 거리여도 필수 도로를 아직 안 거친 경우
                dist[nxt][0] = dist[cur][0] + nxt_cost;
                pq.push({dist[nxt][0], nxt});
                if (cur == g && nxt == h || cur == h && nxt == g) {
                    dist[nxt][1] = true;
                    continue;
                }
                if (dist[cur][1]) {
                    dist[nxt][1] = true;
                } else {
                    dist[nxt][1] = false;
                }
            }
        }
        // debug
//        for (int i = 1; i <= n; i++) {
//            cout << dist[i][0] << ' ' << dist[i][1] << '\n';
//        }

        // 출력
        sort(dest.begin(), dest.end());
        for (int i: dest) {
            if (dist[i][1])
                cout << i << ' ';
        } cout << '\n';
    }
}


/*
목잡은 test case:
1
5 5 1
1 3 5

1 2 1
2 4 2
2 3 2
3 5 3
4 5 3
5
 */