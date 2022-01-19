#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// p. 262: 전보
// 다익스트라
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
#define cost first // 우선순위큐 다루기 쉽게 그래프 간선 저장과 우선순위 큐에서 cost 값이 먼저오도록 !!!
#define vtx second

using namespace std;

int d[30001];
vector<pair<int, int> > v[30001];
// vector<vector<pair<int, int> > > v(N+1); // 내가 작성했던 방법, 삽입 시 v[1].push_back({3, 5}), 접근 시 v[1][3]

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push({0, start}); // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    d[start] = 0;
    while (!pq.empty()) {
        int cur = pq.top().vtx, cur_cost = -pq.top().cost;
        pq.pop();

        if (d[cur] < cur_cost) continue; // from 갱신 여부 파악

        // 갱신 코드
        for (auto &i: v[cur]) {
            int nxt = i.vtx, nxt_cost = i.cost + cur_cost;
            if (nxt_cost < d[nxt]) {
                d[nxt] = nxt_cost;
                pq.push({-nxt_cost, nxt});
            }
        }
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({z, y});
    }

    fill(d, d + 30001, INF);
    dijkstra(s);

    int cnt = 0;
    int max_dis = 0;
    for (int i = 1; i <= n; i++) {
        // 도달할 수 있는 노드인 경우
        if (d[i] != INF) {
            cnt += 1;
            max_dis = max(max_dis, d[i]);
        }
    }

    // 시작 노드는 제외해야 하므로 cnt - 1을 출력
    cout << cnt - 1 << ' ' << max_dis << '\n';
}