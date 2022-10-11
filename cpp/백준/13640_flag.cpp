#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
struct info {
    int ry, rx, by, bx, count;
};

char map[11][11];
int visited[10][10][10][10];

int bfs(info st) {
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    int ret = -1;
    queue<info> q;
    q.push(st);
    visited[st.ry][st.rx][st.by][st.bx] = 1;
    while (!q.empty()) {
        auto [ry, rx, by, bx, count] = q.front();
        q.pop();
        if (count > 10) break;
        // 최솟값 반환
        if (map[ry][rx] == 'O' && map[by][bx] != 'O') {
            ret = count;
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            int n_ry = ry;
            int n_rx = rx;
            int n_by = by;
            int n_bx = bx;

            while (true) {
                if (map[n_ry][n_rx] == '#') { // 벽이면 후퇴하고 멈춤
                    n_ry -= dy[dir], n_rx -= dx[dir];
                    break;
                }
                if (map[n_ry][n_rx] == 'O') { // 홀이면 그 자리에서 멈춤
                    break;
                }
                n_ry += dy[dir], n_rx += dx[dir];
            }

            while (true) {
                if (map[n_by][n_bx] == '#') {
                    n_by -= dy[dir], n_bx -= dx[dir];
                    break;
                }
                if (map[n_by][n_bx] == 'O') {
                    break;
                }
                n_by += dy[dir], n_bx += dx[dir];
            }

            if (n_rx == n_bx && n_ry == n_by) { // 같은 위치 처리
                if (map[n_ry][n_rx] == 'O') continue;
                int r_dist = abs(n_ry - ry) + abs(n_rx - rx);
                int b_dist = abs(n_by - by) + abs(n_bx - bx);
                if (r_dist > b_dist) {
                    n_ry -= dy[dir], n_rx -= dx[dir];
                } else {
                    n_by -= dy[dir], n_bx -= dx[dir];
                }
            }
            if (visited[n_ry][n_rx][n_by][n_bx] == 0) {
                visited[n_ry][n_rx][n_by][n_bx] = 1;
                q.push({n_ry, n_rx, n_by, n_bx, count + 1});
            }
        }
    } return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> map[i];
    info st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'R') {
                st.ry = i, st.rx = j;
            }
            if (map[i][j] == 'B') {
                st.by = i, st.bx = j;
            }
        }
    }
    st.count = 0;
    cout << bfs(st);
}
