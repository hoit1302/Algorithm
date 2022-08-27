#include <iostream>
#include <vector>
using namespace std;

vector<string> color;
vector<vector<bool>> visited;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y, int n) {
    visited[x][y] = true;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || n <= nx || n <= ny || visited[nx][ny] ||
            color[x][y] != color[nx][ny]) { // 탈락 조건: 범위 벗어남, 이미 방문함, 색이 다름
            continue;
        }
        dfs(nx, ny, n);
    }
}

int main() {
    int n;
    cin >> n;
    color.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    // RGB 구분 영역 개수 찾기
    visited.assign(n, vector<bool>(n, false));
    int normal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                normal++;
                dfs(i, j, n);
            }
        }
    }

    // G 영역을 R로 바꾸기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (color[i][j] == 'G') {
                color[i][j] = 'R';
            }
        }
    }
    // RB 구분 영역 개수 찾기
    visited.assign(n, vector<bool>(n, false));
    int same_g_r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                same_g_r++;
                dfs(i, j, n);
            }
        }
    }
    cout << normal << ' ' << same_g_r << '\n';
}