#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * 연구소 [#](https://www.acmicpc.net/problem/14502)
 * 풀이시간: 딱 40분
 */
int n, m;
typedef vector<vector<int> > matrix;
matrix m1, m2;

void spreadVirus(int x, int y) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
        if (m2[nx][ny] == 0) {
            m2[nx][ny] = 2;
            spreadVirus(nx, ny);
        }
    }
}

int calSafe(vector<int> &tmp) {
    m2.assign(m1.begin(), m1.end());
    // 1. 벽 세우기
    for (int i = 0; i < 3; i++) {
        if (m1[tmp[i] / m][tmp[i] % m] != 0) {
            return 0; // 새로 벽을 새울 수 없음
        }
        m2[tmp[i] / m][tmp[i] % m] = 1;
    }
    // 2. 바이러스 퍼뜨리기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (m2[i][j] == 2) {
                spreadVirus(i, j);
            }
        }
    }

    // 3. 안전 영역 계산하기
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (m2[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {

    cin >> n >> m;
    m1.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> m1[i][j];
        }
    }
    int ans = 0;
    vector<bool> com(n * m, false);
    for (int i = 0; i < 3; i++) {
        com[i] = true;
    }
    do {
        vector<int> tmp;
        for (int i = 0; i < n * m; i++) {
            if (com[i]) {
                tmp.push_back(i);
            }
        }
        ans = max(ans, calSafe(tmp));
    } while (prev_permutation(com.begin(), com.end()));
    cout << ans;
}