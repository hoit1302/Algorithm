#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

/*
 * [#](https://www.acmicpc.net/problem/2178)
 */
int main() {
    // 입력
    int n, m;
    cin >> n >> m;
    vector<vector<int> > maze(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) { // 괴물: -1, 방문하지 않은 길: 0
            maze[i][j] = (str[j] - '0') - 1;
        }
    }
    // 계산
    // 1로만 다닐 수 있음.
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue<ci> q;
    q.push({0, 0});
    maze[0][0] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || m <= ny || maze[nx][ny]) continue;
            q.push({nx, ny});
            maze[nx][ny] = maze[x][y] + 1;
        }
    } cout << maze[n - 1][m - 1];
}