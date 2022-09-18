#include <vector>
#include <iostream>
using namespace std;

int ch[1000][1000];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size(), m = board[0].size();
    // 1. 누적합 초기화하기
    for (vector<int> s: skill) {
        int type = s[0], degree = s[5];
        int r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4];
        ch[r1][c1] += (type == 1) ? -degree : degree;
        if (r2 + 1 < n  && c2 + 1 < m) {
            ch[r2 + 1][c2 + 1] += (type == 1) ? -degree : degree;
        }
        if (r2 + 1 < n) {
            ch[r2 + 1][c1] += (type == 2) ? -degree : degree;
        }
        if (c2 + 1 < m) {
            ch[r1][c2 + 1] += (type == 2) ? -degree : degree;
        }
    }
    // debug
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << ch[i][j] << ' ';
    //     } cout << '\n';
    // }
    // 2. 누적합 계산하기
    // 2-1. 왼쪽에서 오른쪽으로
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            ch[i][j] += ch[i][j - 1];
        }
    }
    // 2-2. 위에서 아래로
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            ch[j][i] += ch[j - 1][i];
        }
    }
    // 3. 변화량 적용하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] += ch[i][j];
        }
    }
    // 4. 파괴되지 않은 건물의 개수 세기
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (0 < board[i][j]) {
                cnt++;
            }
        }
    } return cnt;
}