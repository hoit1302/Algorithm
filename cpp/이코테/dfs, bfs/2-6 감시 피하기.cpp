#include <iostream>
#include <vector>
#include <algorithm>
/*
 * 감시 피하기[#](https://www.acmicpc.net/problem/18428)
 * 풀이시간: 40분
 * 절대 어려운 문제가 아닌데 애먹음.
 * 배열 복사는 copy 함수가 있는데 그냥 손수하는 것이 가장 편함.
 * 복사하는 건 벡터가 쉬움
 */
using namespace std;
typedef pair<int, int> ci;
vector<ci> t;
vector<vector<char>> hallway;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isPos(int n, vector<int> &select) {
    vector<vector<char>> cp(hallway.begin(), hallway.end());
    for (int i = 0; i < select.size(); i++) {
        int r = select[i] / n, c = select[i] % n;
        if (cp[r][c] != 'X') return false;
        cp[r][c] = 'O';
    }

    for (auto [i, j]: t) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + i, ny = dy[dir] + j;
            while (true) {
                // cout << nx << ' ' << ny << '\n';
                if (nx < 0 || ny < 0 || n <= nx || n <= ny || cp[nx][ny] == 'O') {
                    break;
                }
                if (cp[nx][ny] == 'S') {
                    return false;
                }
                nx += dx[dir], ny += dy[dir];
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    hallway.assign(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> hallway[i][j];
            if (hallway[i][j] == 'T')
                t.push_back({i, j});
        }
    }
    vector<bool> comb(n * n, false);
    for (int i = 0; i < 3; i++) {
        comb[i] = true;
    }
    bool flag = false;
    do {
        vector<int> select;
        for (int i = 0; i < n * n; i++) {
            if (comb[i]) {
                select.push_back(i);
            }
        }
        if (isPos(n, select)) {
            flag = true;
            break;
        }
    } while (prev_permutation(comb.begin(), comb.end()));
    cout << (flag ? "YES" : "NO");
}