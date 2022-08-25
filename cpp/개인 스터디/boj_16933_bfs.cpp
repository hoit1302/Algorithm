#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dist[1000][1000][11][2];
struct info {
    int x, y, br, t;
};
int toggle(int i) {
    return (i == 0) ? 1 : 0;
}
int bfs(int n, int m, int k, vector<vector<char>> &graph) {
    for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) for (int a = 0; a < 11; a++) for (int b = 0; b<2; b++) {
        dist[i][j][a][b] = INF;
    }
    queue<info> q;
    dist[0][0][0][0] = 1; // 0: 낮, 1: 밤
    q.push({0, 0, 0});
    while (!q.empty()) {
        auto [x, y, br, t] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i], n_br = br, nt = toggle(t);
            if (nx < 0 || ny < 0 || n <= nx || m <= ny)
                continue;
            int nxt_dist = dist[x][y][br][t] + 1;
            if (graph[nx][ny] == '1') {
                if (t == 1) {
                    if (dist[x][y][br][nt] == INF) {
                        dist[x][y][br][nt] = nxt_dist;
                        q.push({x, y, br, nt});
                    }
                    continue;
                }
                if (++n_br == k + 1)
                    continue;
                if (dist[nx][ny][n_br][nt] == INF) {
                    dist[nx][ny][n_br][nt] = nxt_dist;
                    q.push({nx, ny, n_br, nt});
                }
            } else {
                if (dist[nx][ny][br][nt] == INF) {
                    dist[nx][ny][br][nt] = nxt_dist;
                    q.push({nx, ny, br, nt});
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(dist[n - 1][m - 1][i][j], ans);
        }
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
// 17%에서 메모리 초과가 나서 구글링하다가 개선할 수 있는 부분을 많이 찾게 되었다.
// 1. vector가 배열보다 더 큰 메모리 공간을 차지한다. (이 부분만 고쳤더니 ac를 받았다 흑... 내시간)
// 2. 0과 1을 간단하게 toggle하는 방법: 1 - value
// 현재 값이 0일 때, (1-0)-> 1이 되고, 현재 값이 1일 때 (1-1) 0이 된다.