#include <vector>
#include <iostream>
using namespace std;

int n, m;
vector<vector<int>> b;

void change(int type, int r1, int c1, int r2, int c2, int degree) {
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            b[i][j] += (type == 1) ? -degree: degree;
        }
    }
}

int calSurviveCnt() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (0 < b[i][j]) {
                cnt++;
            }
        }
    } return cnt;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    n = board.size(), m = board[0].size();
    b.assign(board.begin(), board.end()); // vector의 장점, 2차원 벡터 복사가 쉬움
    for (vector<int> s: skill) {
        change(s[0], s[1], s[2], s[3], s[4], s[5]);
    }
    return calSurviveCnt();
}