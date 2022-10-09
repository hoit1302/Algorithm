#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> ci;
int dist_f[1000][1000], dist[1000][1000];
int simul(int n, int m, vector<string> &g) {
    // 1. dist 배열과 큐 초기화
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        dist_f[i][j] = -1, dist[i][j] = -1;
    }
    queue<ci> qf, q;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (g[i][j] == '*') {
            qf.push({i, j});
            dist_f[i][j] = 0;
        } else if (g[i][j] == '@') {
            q.push({i, j});
            dist[i][j] = 0;
        }
    }
    // 2. bfs
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!qf.empty()) {
        auto [x, y] = qf.front(); qf.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
            if (g[nx][ny] == '#' || dist_f[nx][ny] != -1) continue;
            qf.push({nx, ny});
            dist_f[nx][ny] = dist_f[x][y] + 1;
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || m <= ny)
                return dist[x][y] + 1;
            if (g[nx][ny] == '#' || dist[nx][ny] != -1) continue;
            if (dist_f[nx][ny] != -1 && dist[x][y] + 1 >= dist_f[nx][ny]) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    return -1;
}

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int tc;
    string res;
    cin >> tc;
    while (tc--) {
        int m, n;
        cin >> m >> n;
        vector<string> graph(n);
        for (int i = 0; i < n; i++) {
            cin >> graph[i];
        }
        int t = simul(n, m, graph);
        res += (t == -1 ? "IMPOSSIBLE" : to_string(t)) + '\n';
    } cout << res;
}
/*
 * [불](https://www.acmicpc.net/problem/5427)
 * 아이디어 가져가기
 * 불이 번지는 시간을 다 기록해두고 시작점에서 출발하여 조건에 맞는 길을 찾는다.
 * 2번의 bfs를 수행하는데, 2개의 dist 배열을 사용한다.
 *
 * bfs는 자료구조 어떻게 설정하냐가 중요하다.
 * dist 배열을 사용하면 q에 좌표만 넣으면 된다.
 * dist 배열을 사용하면 않으면 q에 좌표값, 거리, 조건 값을 넣어 관리해야한다.
 *
 * 42번줄: '불이 언젠가 번지고', 시기가 내가 밟기 이전이라면
 * 전제 조건을 빠뜨려서 맞왜틀
 */
