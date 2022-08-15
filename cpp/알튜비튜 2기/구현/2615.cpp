#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 20;
int board[SIZE][SIZE];

bool isWin(int kind, int r, int c) {
    // ↗ → ↘ ↓ 방향으로 같은 수 세기
    int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
    int dy[] = {1, -1, 1, -1, 1, -1, 0, 0};

//    cout << r << ' ' << c << ' ' << kind << '\n';
    vector<int> cnt(8, 0);
    for (int dir = 0; dir < 8; dir++) {
        int cur_x = r, cur_y = c;
        while (true) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if (nx < 1 || SIZE <= nx || ny < 1 || SIZE <= ny) {
                break;
            }
            if (kind == board[nx][ny]) {
                cnt[dir]++;
            } else {
                break;
            }
            cur_x = nx;
            cur_y = ny;
        }
    }

    for (int i = 0; i < 4; i++) {
//        cout << cnt[i * 2] << ", " << cnt[i * 2 + 1] << '\n';
        int result = cnt[i * 2] + cnt[i * 2 + 1] + 1;
        if (i == 0) {
            if (result == 5 && cnt[i * 2 + 1] == 0) {
                return true;
            } continue;
        }
        if (result == 5) {
            return true;
        }
    }
    return false;
}

/*
 * 오목 [#](https://www.acmicpc.net/problem/2615)
 * ↙↗ ←→ ↖↘ ↑↓ 방향으로 같은 종류의 연속된 개수 세기
 * 가장 왼쪽에 있는 바둑알 위치를 출력해야함: 맨 위부터 탐색하므로 우상향 대각선 다룰 때 예외 처리해주기
 */
int main() {
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] && isWin(board[i][j], i, j)) {
                cout << board[i][j] << '\n';
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
    cout << "0\n";
}