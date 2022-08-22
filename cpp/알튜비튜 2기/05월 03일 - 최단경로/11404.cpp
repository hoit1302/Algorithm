#include <iostream>
#include <vector>
/*
 * 플로이드 [#](https://www.acmicpc.net/problem/11404)
 * 너무나 당연하게도 플로이드와샬
 */

#define INF 1e9
using namespace std;
typedef vector<vector<int>> matrix;
matrix graph;
void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    graph.assign(n + 1, vector<int>(n + 1, INF));
    while (m--) {
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w);
    }
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    floyd(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' ';
        } cout << '\n';
    }
}