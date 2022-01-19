#include <iostream>
#include <vector>

#define inf 1e9
using namespace std;

// p. 259: 미래 도시
// 플로이드 와샬

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, x, y, X, K;
    cin >> N >> M;
    int dis[N + 1][N + 1];
    fill(&dis[0][0], &dis[N][N + 1], inf);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dis[i][i] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        dis[x][y] = 1;
        dis[y][x] = 1;
    }
    cin >> X >> K;

    // 플로이드 와샬 알고리즘
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int res = dis[1][K] + dis[K][X];
    if (res >= inf)
        cout << "-1" << "\n";
    else
        cout << res << "\n";
    return 0;
}
