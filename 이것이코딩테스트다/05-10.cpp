#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> v;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j) {
    // 방문함.
    /// for loop 4 방향에 대해서
    // 해당 방향에 대해서 (움직인 방향에 대한 범위 체크) 방문하지 않았다면
    // dfs 호출
    v[i][j] = '1';
    for (int d = 0; d < 4; d++) {
        int r = dx[d] + i, c = dy[d] + j;
        if (r < 0 || N-1 < r || c < 0 || M-1 < c)
            continue;
        if (v[r][c] == '0')
            dfs(r, c);
    }
}

// p. 149: 음료수 얼려 먹기
int main() {
    freopen("../input.txt", "r", stdin);
    int res = 0;
    string tmp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '0') {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res << "\n";
    return 0;
}
