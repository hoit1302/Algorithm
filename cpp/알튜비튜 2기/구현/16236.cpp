#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
/*
 * 아기 상어 [#](https://www.acmicpc.net/problem/16236)
 * 소요 시간: 45분
 */
int space[20][20];
int dist[20][20];
typedef pair<int, int> ci;
struct info {
    int dist, x, y;
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
info findEatable(int n, ci sh_pos, int size) {
    vector<ci> ans;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        dist[i][j] = -1;
    }
    int min_dist = INF;
    queue<ci> q;
    q.push({sh_pos.first, sh_pos.second});
    dist[sh_pos.first][sh_pos.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (min_dist <= dist[x][y])
            continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || n <= ny || dist[nx][ny] != -1 || space[nx][ny] > size) continue;
            dist[nx][ny] = dist[x][y] + 1;
            // 빈칸아닌 먹을 수 있는 물고기일 때
            if (space[nx][ny] && space[nx][ny] < size) {
                ans.push_back({nx, ny});
                min_dist = min(min_dist, dist[nx][ny]);
                continue;
            }
            // 빈칸이거나 같은 크기이면 이동만 함.
            q.push({nx, ny});
        }
    }
    if (ans.empty()) {
        return {-1, 0, 0};
    }
    sort(ans.begin(), ans.end());
    return {min_dist, ans[0].first, ans[0].second};
}

int calTime(int n, ci sh_pos) {
    int res = 0, size = 2, cnt = 0;
    while (true) {
        info fishes = findEatable(n, sh_pos, size);
        if (fishes.dist == -1) { // 탈출 조건
            return res;
        }
        // 가장 가까운 물고기 먹기
        res += fishes.dist;
        sh_pos = {fishes.x, fishes.y};
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