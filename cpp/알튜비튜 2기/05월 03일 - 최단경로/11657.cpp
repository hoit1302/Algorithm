#include <iostream>
#include <vector>

/*
 * 타임머신 [#](https://www.acmicpc.net/problem/11657)
 * 벨만 포드인 건 알겠는데 구현 방법이 아직 명확하게 박히지 않음.
 */
using namespace std;
typedef long long ll;
#define INF 1e18
struct edge {
    int u, v;
    ll w;
};
vector<edge> edges;

vector<ll> bellmanFord(int n, int m) {
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        bool is_ch = false; // 갱신 확인
        for (int j = 0; j < m; j++) {
            auto [u, v, w] = edges[j];
            if (dist[u] == INF) { // 이 간선으로 출발 불가능
                continue;
            }
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                is_ch = true;
                if (i == n) {
                    return {-1};
                }
            }
        }
        if (!is_ch) { // 더 이상 갱신되지 않으므로 반복문 끊음.
            break;
        }
    }
    return dist;
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<ll> ans = bellmanFord(n, m);
    if (ans[0] == -1) {
        cout << "-1";
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        cout << (ans[i] == INF ? -1 : ans[i]) << '\n';
    }
}