#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct info {
    int x, y, br;
};
int bfs(int n, int m, int k, vector<vector<char>> &graph) {
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
    queue<info> q;
    dist[0][0][0] = 1;
    q.push({0, 0, 0});
    while (!q.empty()) {
        auto [x, y, br] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i], n_br = br;
            if (nx < 0 || ny < 0 || n <= nx || m <= ny)
                continue;
            if (graph[nx][ny] == '1') n_br++;
            if (n_br == k + 1 || dist[nx][ny][n_br] != INF) continue;
            dist[nx][ny][n_br] = dist[x][y][br] + 1;
            q.push({nx, ny, n_br});
        }
    }
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        ans = min(dist[n-1][m-1][i], ans);
    }
    if (ans == INF) return -1;
    return ans;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> graph(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    cout << bfs(n, m, k, graph);
}