#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> ci;
const int INF = 2e9;

int dist[201][3];
vector<vector<ci>> graph;
void dijkstra(int idx, int start) {
    priority_queue<ci, vector<ci>, greater<>> pq; // 누적 거리, 도착 정점
    dist[start][idx] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (dist[cur][idx] < cost) continue;
        for (auto [nxt, n_cost]: graph[cur]) {
            if (dist[nxt][idx] <= dist[cur][idx] + n_cost) continue;
            dist[nxt][idx] = dist[cur][idx] + n_cost;
            pq.push({dist[nxt][idx], nxt});
        }
    }
}

/*
* [합승 택시 요금](https://school.programmers.co.kr/learn/courses/30/lessons/72413)
 * 30분 소요
 * 대박... 한 번에 맞았다 🥲😭
 * s, a, b를 시작점으로 각각 다익스트라 수행 후 각 정점까지 합승할 때의 모든 택시 요금을 고려해 최저 택시 요금을 알아냄
 * 19900 (간선의 수) * 1e5 (택시 요금) = 19억 9천만 < 21억 (int 범위)
 * int 범위 내이지만 주의해서 무한의 값을 20억정도로 잡아야함.
 * 시간 복잡도: O(3 * (VlogV + ElogV) + 200)
 */
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 1; i <= 200; i++) { // dist 초기화
        fill_n(dist[i], 3, INF);
    }
    graph.assign(n + 1, vector<ci>());
    for (vector<int> f: fares) { // graph 만들기, 양방향
        graph[f[0]].push_back({f[1], f[2]});
        graph[f[1]].push_back({f[0], f[2]});
    }
    // 3번의 다익스트라 수행
    dijkstra(0, s);
    dijkstra(1, a);
    dijkstra(2, b);
    // 정답 계산
    int ans = INF;
    for (int i = 1; i <= n; i++) { // i까지 합승하고 i부터 각 집까지 따로 감
        // cout << i << "까지 합승할 때 "<< dist[i][0] << "이고, " << dist[i][1] << " " << dist[i][2] << '\n';
        ans = min(ans, dist[i][0] + dist[i][1] + dist[i][2]);
    }
    return ans;
}