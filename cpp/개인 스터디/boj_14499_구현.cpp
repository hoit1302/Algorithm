#include <iostream>

using namespace std;
int map[20][20];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dice[4][3];

void rollNorth() {
    int top = dice[0][1];
    for (int i = 0; i < 3; i++)
        dice[i][1] = dice[i + 1][1];
    dice[3][1] = top;
}

void rollEast() {
    int r = dice[1][2], b = dice[3][1];
    for (int i = 2; i >= 1; i--)
        dice[1][i] = dice[1][i - 1];
    dice[1][0] = b;
    dice[3][1] = r;
}

void rollDice(int dir) {
    if (dir == 1) {
        rollEast();
    } else if (dir == 2) {
        int a = 3;
        while (a--)
            rollEast();
    } else if (dir == 3) {
        rollNorth();
    } else {
        int a = 3;
        while (a--)
            rollNorth();
    }
}

/*
 * 주사위 굴리기 [#](https://www.acmicpc.net/problem/14499)
 * 말 그대로 주사위 굴리는 것을 구현하는 문제.
 * 문제에서 주어진 주사위는 전형적인 정육면체이다.
 * 내가 구현한 것처럼 동쪽을 구현하고 서쪽은 동쪽 3번으로 구현할 수도 있지만
 * 전개도의 모든 경우 수 4가지를 구해서 아래와 같이 요소를 재정의하여 변경할 수 있다.
 * dice = {dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]};
 */
int main() {
    // c++ 기준 40ms, 0ms 의 차이는 입출력에서 난다.
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m, x, y, k, dir;
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    while (k--) {
        cin >> dir;
        int nx = x + dx[dir - 1], ny = y + dy[dir - 1];
        if (nx < 0 || ny < 0 || n <= nx || m <= ny)
            continue;

        x = nx;
        y = ny;
        rollDice(dir);
        if (map[x][y] == 0) {
            map[x][y] = dice[3][1];
        } else {
            dice[3][1] = map[x][y];
            map[x][y] = 0;
        }
        cout << dice[1][1] << '\n';
    }
}