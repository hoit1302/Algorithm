#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
/*
 * 벽 부수고 이동하기 [#](https://www.acmicpc.net/problem/2206)
 * 도움 받은 설명: https://youtu.be/DppIIIsR6nk
 *
 * 최단거리를 구할 때 dist 배열에 시작점에서부터 x까지의 최단 거리의 상태를 저장하게 된다.
 * 이 때 최단거리 이외의 부차적인 정보를 저장하고 싶다면 **dist 배열의 차원을 추가**해야한다!
 * 예를 들어 벽을 부수지 않고 온 최단 거리는 dist[x][0], 부숴서 온 최단 거리는 dist[x][1]에 저장한다.
 * 강의에서는 이를 `격자형 그래프` 라고 칭하고 있다.
 *
 * + bfs 구현 시, 첫 방문이 최단 거리임을 보장함!
 * 방문했음 == 최단 경로로 갱신되었음!!!
 */
struct info {
    int x, y, is_br;
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int n, int m, vector<vector<int> > &graph) {
    queue<info> q;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INF)));
    dist[0][0][0] = dist[0][0][1] = 1;
    q.push({0, 0, 0});
    while (!q.empty()) {
        auto [x, y, is_br] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
            int n_br = is_br;
            if (graph[nx][ny]) {
                n_br++;
            }
            if (n_br == 2) {
                continue;
            }
            if (dist[nx][ny][n_br] == INF) {
                dist[nx][ny][n_br] = dist[x][y][is_br] + 1;
                q.push({nx, ny, n_br});
            }
        }
    }

    if (dist[n - 1][m - 1][0] == INF && dist[n - 1][m - 1][1] == INF) {
        return -1;
    }
    return min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
}

int main() {
    int n, m;
    cin >> n >> m;
    string str;
    vector<vector<int> > graph(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            graph[i][j] = str[j] - '0';
        }
    }
    cout << bfs(n, m, graph);
}