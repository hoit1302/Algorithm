#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * 2048 (Easy) [#](https://www.acmicpc.net/problem/12100)
 * move 핵심 로직도, board를 돌려 backtracking 시키는 것도 다시 구현하면서 생각해볼 좋은 문제.
 */
typedef vector<vector<int>> matrix;
int n, res = 0;

int findMaxBlock(matrix board) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, board[i][j]);
        }
    }
    return ans;
}
matrix trans(matrix board) {
    matrix t(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[i][j] = board[j][i];
        }
    }
    return t;
}

matrix move(matrix board) {
    matrix temp(n, vector<int>(n, 0)); //새롭게 블록 저장할 배열
    for (int j = 0; j < n; j++) {
        int idx = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (!board[i][j]) {
                continue;
            }
            if (board[i][j] == prev) {
                temp[idx - 1][j] *= 2;
                prev = 0;
            } else {
                temp[idx++][j] = board[i][j];
                prev = board[i][j];
            }
        }
    }
    return temp;
}

void backtracking(int dep, matrix board) {
    if (dep == 6) {
        res = max(res, findMaxBlock(board));
        return;
    }

    //상
    backtracking(dep + 1, move(board));
    //하
    reverse(board.begin(), board.end());
    backtracking(dep + 1, move(board));
    //좌
    matrix board_t = trans(board);
    backtracking(dep + 1, move(board_t));
    //우
    reverse(board_t.begin(), board_t.end());
    backtracking(dep + 1, move(board_t));
}

int main() {
    cin >> n;
    matrix board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    reverse(board.begin(), board.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        } cout << '\n';
    }
    backtracking(1, board);
    cout << res;
}
