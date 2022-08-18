#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/*
 * [#](https://www.acmicpc.net/problem/18405)
 * 풀이 시간: 36분
 * 거리 제한 bfs와 커스텀하는 정렬 두 가지 출제
 * 거리 제한 bfs는 내가 쓰는 용어이고 55~57의 로직을 뜻함.
 */
using namespace std;
typedef vector<vector<int> > matrix;
typedef pair<int, int> ci;

struct info {
    int virus, x, y;
};

bool compare(info &a, info &b) {
    if (a.virus != b.virus) {
        return a.virus < b.virus;
    }
    return a.x < b.x;
}

int bfs(int n, int k, int s, int r_x, int r_y, matrix &mat) {
    // 초기화
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    matrix vi(n, vector<int>(n, -1)); // 감염된 시간 저장
    vector<info> q_ele;
    queue<ci> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) {
                vi[i][j] = 0;
                q_ele.push_back({mat[i][j], i, j});
            }
        }
    }
    sort(q_ele.begin(), q_ele.end(), compare);
    for (info i: q_ele) {
        q.push({i.x, i.y});
    }

    // bfs
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || n <= ny || vi[nx][ny] != -1)
                continue;
            mat[nx][ny] = mat[x][y];
            vi[nx][ny] = vi[x][y] + 1;
            if (vi[nx][ny] < s) { // 2초까지만
                q.push({nx, ny});
            }
        }
    }
    return mat[r_x - 1][r_y - 1];
}

int main() {
    int n, k, s, x, y;
    cin >> n >> k;
    matrix mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> s >> x >> y;
    if (s == 0) {
        cout << mat[x - 1][y - 1];
        return 0;
    }
    cout << bfs(n, k, s, x, y, mat);

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << mat[i][j] << ' ';
//        } cout << '\n';
//    }
}