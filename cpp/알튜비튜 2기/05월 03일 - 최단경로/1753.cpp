#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e9;
vector<vector<ci>> graph;

/*
 * 최단 경로 [#](https://www.acmicpc.net/problem/1753)
 * 너무나 당연하게도 다익스트라
 */
vector<int> dijkstra(int v, int s) {
//    모든 정점까지의 거리를 담은 dist 배열을 INF로 초기화
    vector<int> dist(v + 1, INF);
//    시작 정점까지의 거리를 0으로 초기화
    dist[s] = 0;
    priority_queue<ci, vector<ci>, greater<> > pq; // 시작점으로부터의 거리, 정점
    pq.push({0, s});
    while (!pq.empty()) { // 갱신할 정점이 있을 때까지
//        탐색하지 않은 정점 중 시작점에서 가장 가까운 정점
        auto [f_w, from] = pq.top(); pq.pop();
        if (dist[from] < f_w) {
            continue;
        }
        // from과 연결된 정점의 최단 거리 갱신
        for (auto [to, t_w]: graph[from]) {
            if (dist[from] + t_w < dist[to]) {
                dist[to] = dist[from] + t_w;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int v, e, s, x, y, z;
    cin >> v >> e >> s;
    graph.assign(v + 1, vector<ci>());
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
    }
    vector<int> dist = dijkstra(v, s);
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        }
    }
}
