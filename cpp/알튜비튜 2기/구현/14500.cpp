#include <iostream>
#include <vector>

using namespace std;

/*
 * 테트로미노 [#](https://www.acmicpc.net/problem/14500)
 * 걸린 시간: 1시간
 * 개선 사항
 * 1. visited 배열 없애기.
 * 2. 아이디어
 * 보라색 블럭을 모든 케이스를 나누어 러프하게 구현함. backtracking 함수 안에서 처리할 수 있었음.
 * 3개의 블럭이 결정된 이후에, 가운데에서 탐색해 구현할 수 있음.
 * 3. 가지치기, 나머지의 모든 값이 MAX여도 ans가 더 클 때는 더 이상 탐색할 이유가 없음.
 */

const int MAX = 1000;

int ans, n, m;
vector<vector<int>> board;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }
    // 가지치기, 나머지의 모든 값이 MAX여도 ans가 더 클 때는 더 이상 탐색할 이유가 없음.
    if (ans >= MAX * (4 - cnt) + sum) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i],  nc = col + dc[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) {
            continue;
        }

        if (cnt == 2) {
            int save = board[nr][nc];
            board[nr][nc] = 0;
            backtracking(row, col, cnt + 1, sum + save);
            board[nr][nc] = save;
        }
        int save = board[nr][nc];
        board[nr][nc] = 0;
        backtracking(nr, nc, cnt + 1, sum + save);
        board[nr][nc] = save;
    }
}

int main() {
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int save = board[i][j];
            board[i][j] = 0;
            backtracking(i, j, 1, save);
            board[i][j] = save;
        }
    }

    cout << ans;
    return 0;
}

/*
 * purple block 모양의 최댓값을 확인하기 위해 구현했었음.
int findPurple(int r, int c) {
    int ans = 0;
    if (r != 0 && c != 0 && c != col - 1) { // 맨 위가 아니면 ㅗ 가능
        ans = max(ans, p[r][c - 1] + p[r][c] + p[r][c + 1] + p[r - 1][c]);
    }
    if (r != row - 1 && c != 0 && c != col - 1) { // 맨 아래가 아니면 ㅜ 가능
        ans = max(ans, p[r][c - 1] + p[r][c] + p[r][c + 1] + p[r + 1][c]);
    }
    if (c != 0 && r != 0 && r != row - 1) { // 맨 오른쪽이 아니면 ㅓ 가능
        ans = max(ans, p[r - 1][c] + p[r][c] + p[r + 1][c] + p[r][c - 1]);
    }
    if (c != col - 1 && r != 0 && r != row - 1) { // 맨 왼쪽이 아니면 ㅏ 가능
        ans = max(ans, p[r - 1][c] + p[r][c] + p[r + 1][c] + p[r][c + 1]);
    }
    return ans;
}
 */