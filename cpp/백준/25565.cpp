#include <iostream>

using namespace std;

int garden[2001][2001], row[2001], col[2001];;

int getOneCnt(int n, int m) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (garden[i][j] == 1)
                cnt++;
        }
    }
    return cnt;
}

void same(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (garden[i][j] == 1)
                cout << i << ' ' << j << '\n';
        }
    }
}

void sameRow(int fixed_r, int m, int k, int one_cnt) {
    int first_one = 0;
    for (int i = 1; i <= m; i++) {
        if (garden[fixed_r][i]) {
            first_one = i;
            break;
        }
    }
    int cnt = 2 * k - one_cnt;
    int y = first_one + (k - cnt);
    cout << cnt << '\n';
    while (cnt--) {
        cout << fixed_r << ' ' << y++ << '\n';
    }
}

void sameCol(int n, int fixed_c, int k, int one_cnt) {
    int first_one = 0;
    for (int i = 1; i <= n; i++) {
        if (garden[i][fixed_c]) {
            first_one = i;
            break;
        }
    }
    int cnt = 2 * k - one_cnt;
    int x = first_one + k - cnt;
    cout << cnt << '\n';
    while (cnt--) {
        cout << x++ << ' ' << fixed_c << '\n';
    }
}

void cross(int n, int m) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int r = 0, c = 0;
            if (garden[i][j] != 1) continue;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx <= 0 || ny <= 0 || n < nx || m < ny)
                    continue;
                if (garden[nx][ny] == 1) {
                    if (k < 2) {
                        r++;
                    } else {
                        c++;
                    }
                }
            }
            if (r && c) {
                cout << i << ' ' << j << '\n';
                return;
            }
        }
    }
}
/*
 * 딸기와 토마토 (https://www.acmicpc.net/problem/25565)
 * 유형: 빡구현 (내기준.., 나는 깔끔하게 푸는 법을 모르기 때문에 골드 2~3..? 정도로 봄)
 *
 * 1의 개수를 세서 case를 나눈다.
 *  1. k개라면 전부 겹치는 case
 *  -> 출력 순서대로 순회하면서 씨앗을 심은 칸이면(1이면) 출력
 *  2. 2 * k 개라면 모두 안 겹치는 case
 *  -> 0 출력
 *  3-1. 특정 가로줄에서 겹침
 *  -> case 판단: 단 하나의 행에만 씨앗이 심겼다면 이 케이스에 속함.
 *  -> 출력: 겹치는 개수는 2 * k - one_cnt이고
 *  ->      고정된 row, col는 1이 시작되는 칸 + k - cnt로부터 겹치는 개수만큼 출력
 *  3-2. 특정 세로줄에서 겹침
 *  -> 단 하나의 열에만 씨앗이 심겼다면 이 케이스에 속함.
 *  -> 출력: 겹치는 개수는 2 * k - one_cnt이고
 *  ->      고정된 col, row는 1이 시작되는 칸 + k - cnt로부터 겹치는 개수만큼 출력
 *  4. 딸기와 토마토를 서로 다른 방향으로 심으면서 한 칸만 겹치는 case
 *  -> 씨앗을 심은 칸 주변을 확인하는데, 가로 방향과 세로 방향으로 하나 이상씩 심겨져 있다면 해당 칸 출력
 *
 *
 *  좀 더 깔끔하게 푸는 방법을 알고 싶다...
 */

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> garden[i][j];
            if (garden[i][j] == 1) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    int one_cnt = getOneCnt(n, m); // 1의 개수 세기
    if (one_cnt == k) { // 1. k개라면 전부 겹치는 case
        cout << k << '\n';
        same(n, m);
        return 0;
    }
    if (one_cnt == 2 * k) { // 2. 2 * k 개라면 하나도 안 겹침
        cout << "0\n";
        return 0;
    }
    // 3-1. 특정 가로줄에서 겹침
    int row_cnt = 0, r;
    for (int i = 1; i <= n; i++) {
        if (row[i] == true) {
            row_cnt++;
            r = i;
        }
    }
    if (row_cnt == 1) {
        sameRow(r, m, k, one_cnt);
    }
    // 3-2. 특정 세로줄에서 겹침
    int col_cnt = 0, c;
    for (int i = 1; i <= m; i++) {
        if (col[i] == true) {
            col_cnt++;
            c = i;
        }
    }
    if (col_cnt == 1) {
        sameCol(n, c, k, one_cnt);

    }
    if (one_cnt == 2 * k - 1) { // 4. 가로 세로로 심어서 한 칸만 겹침
        cout << "1\n";
        cross(n, m);
    }
}