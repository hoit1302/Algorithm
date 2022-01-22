#include <iostream>
#include <vector>
#include <queue>

#define x first
#define y second
using namespace std;

int N, M;
int v[201][201];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// p. 152: 미로 탈출
int main() {
    freopen("../input.txt", "r", stdin);
    int res = 0;
    string tmp;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            v[i][j+1] = tmp[j] - '0';
        }
    }

//     큐에서 가장 앞의 원소를 꺼내
//     4 방향으로 (for loop)
//     변경된 위치에서
//     벽이면 무시하고
//     방문하지 않은 원소들의 위치를
//     큐에 삽입
//     방문했음, cost 기록
    queue<pair<int, int> > q;
    q.push({1, 1});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.x == N && cur.y == M) break;

        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cur.x, ny = dy[dir] + cur.y;
            if (nx < 1 || N < nx || ny < 1 || M < ny) continue;
            if (v[nx][ny] == 1) {
                q.push({nx, ny});
                v[nx][ny] = v[cur.x][cur.y] + 1;
            }
        }
    }
    cout << v[N][M] << "\n";
    return 0;
}
