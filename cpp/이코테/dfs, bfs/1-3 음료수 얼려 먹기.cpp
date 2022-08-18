#include <iostream>
#include <vector>

using namespace std;

/*
 * 음료수 얼려 먹기와 유사 문제, 섬의 개수 [#](https://www.acmicpc.net/problem/4963) 풀이
 */
int n, m;
vector<vector<int> > frame;

void dfs(int x, int y) {
    int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

    for (int i = 0; i < 8; i++) {
        int nx = dx[i] + x, ny = dy[i] + y;
        if (nx < 0 || ny < 0 || n <= nx || m <= ny || !frame[nx][ny]) continue;
        frame[nx][ny] = 0;
        dfs(nx, ny);
    }
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (cin >> m >> n) {
        if (n == 0 && m == 0) break;
        frame.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> frame[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (frame[i][j]) {
                    cnt++;
                    frame[i][j] = 0;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
}