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
int n;
vector<ci> t;
vector<vector<char>> hallway, change;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool findStud(int x, int y, int dir_x, int dir_y) {
    if (x < 0 || y < 0 || n <= x || n <= y || change[x][y] == 'O') {
        return false;
    }
    if (change[x][y] == 'S') {
        return true;
    }
    if (findStud(x + dir_x, y +dir_y, dir_x, dir_y)) {
        return true;
    } return false;
}
bool isPos(int n, vector<int> &select) {
    change.assign(hallway.begin(), hallway.end());
    for (int i = 0; i < select.size(); i++) {
        int r = select[i] / n, c = select[i] % n;
        if (change[r][c] != 'X') return false;
        change[r][c] = 'O';
    }

    for (auto [i, j]: t) {
        for (int dir = 0; dir < 4; dir++) {
            if (findStud(dx[dir] + i,  dy[dir] + j, dx[dir], dy[dir]))
                return false;
        }
    }
    return true;
}

int main() {
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
        for (int a: select) {
            cout << a << ' ';
        } cout << '\n';
        if (isPos(n, select)) {
            flag = true;
            break;
        }
    } while (prev_permutation(comb.begin(), comb.end()));
    cout << (flag ? "YES" : "NO");
}