#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
 * 아기 상어 [#](https://www.acmicpc.net/problem/16236)
 * 소요 시간: 45분
 * 구현하면서도 어떻게 단축시킬 수 있을까 계속 고민하게 만들던 문제.
 */
int space[20][20];
int dist[20][20];
typedef pair<int, int> ci;
struct info {
    int dist, x, y;
};
int cmp(const info &a, const info &b) {
    if (a.dist != b.dist) return a.dist < b.dist;
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<info> findEatable(int n, ci sh_pos, int size) {
    vector<info> ans;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        dist[i][j] = -1;
    }
    queue<ci> q;
    q.push({sh_pos.first, sh_pos.second});
    dist[sh_pos.first][sh_pos.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || n <= ny) continue;
            // 처음 방문하고 빈칸아닌 먹을 수 있는 물고기일 때
            if (dist[nx][ny] == -1 && space[nx][ny] && space[nx][ny] < size) {
                dist[nx][ny] = dist[x][y] + 1;
                ans.push_back({dist[nx][ny], nx, ny});
            }
            // 처음 방문하고 빈칸이거나 같은 크기이면 이동만 함.
            if (dist[nx][ny] == -1 && (!space[nx][ny] || space[nx][ny] == size)) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    return ans;
}

int calTime(int n, ci sh_pos) {
    int res = 0, size = 2, cnt = 0;
    while (true) {
        vector<info> fishes = findEatable(n, sh_pos, size);
        if (fishes.empty()) { // 탈출 조건
            return res;
        }
        // 가장 가까운 물고기 먹기
        sort(fishes.begin(), fishes.end(), cmp);
        res += fishes[0].dist;
        sh_pos = {fishes[0].x, fishes[0].y};
        space[sh_pos.first][sh_pos.second] = 0;
        cnt++;
        if (cnt == size) {
            cnt = 0;
            size++;
        }
    }
}

int main() {
    int n;
    ci sh_pos;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> space[i][j];
            if (space[i][j] == 9) { // 아기 상어가 있는 곳
                sh_pos = {i, j};
                space[i][j] = 0;
            }
        }
    }
    cout << calTime(n, sh_pos);
}