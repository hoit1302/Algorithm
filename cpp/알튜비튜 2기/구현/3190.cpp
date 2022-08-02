#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

/*
 * 뱀 [#](https://www.acmicpc.net/problem/3190)
 *
 * 아이디어: 덱을 활용하여 쉽게 뱀의 위치 정보를 갱신할 수 있음.
 * 그래프 문제에서 범위 초과 판단할 때 주의깊게 작성하기!!!
 * if (x < 0 || y < 0 || n <= x || n <= y) continue;
 * map<int, char> cmd;
 * if (cmd[t]) -> t라는 key가 있을 때: null이 아닌 다른 값이면 true
 * t라는 key가 존재하지 않을 때: 에러를 던지지 않고 key를 삽입시키고 value는 null로 할당돼 false를 리턴
 */

typedef pair<int, int> ci;

int dx[] = {0, 1, 0, -1}; // →↓←↑
int dy[] = {1, 0, -1, 0};

int changeDir(int dir, char ch) {
    if (ch == 'L') {
        return (dir + 3) % 4;
    }
    return (dir + 1) % 4;
}

int play(int n, vector<vector<int>> &b, map<int, char> cmd) {
    deque<ci> dq;
    int dir = 0, x = 0, y = 0, t = 0; // 초기화 방향: →

    b[0][0] = 0;
    dq.push_back({0, 0});
    while (true) {
        t++;
        x += dx[dir], y += dy[dir];
        // 게임 종료 조건: 벽 또는 자신의 몸과 부딪힘
        if (x < 0 || y < 0 || n <= x || n <= y || b[x][y] == 0) {
            return t;
        }

        dq.push_front({x, y});
        // 사과 없으면 뱀 꼬리 이동
        if (b[x][y] != 1) {
            auto [end_x, end_y] = dq.back(); dq.pop_back();
            b[end_x][end_y] = -1;
        }
        b[x][y] = 0; // 다음 칸에 뱀 위치
        // 방향 전환
        cout << cmd[t] << '\n';
        if (cmd[t]) {
            dir = changeDir(dir, cmd[t]);
        }
    }
}

int main() {
    // 입력
    int n, k, r, c, l;
    char ch;
    cin >> n;
    // board -1:비어있음, 0: 뱀, 1: 사과
    vector<vector<int>> board(n, vector<int>(n, -1));
    cin >> k;
    while (k--) {
        cin >> r >> c;
        board[r - 1][c - 1] = 1;
    }
    cin >> l;
    map<int, char> cmd;
    while (l--) {
        cin >> c >> ch;
        cmd[c] = ch;
    }

    // 연산, 출력
    cout << play(n, board, cmd);
}
