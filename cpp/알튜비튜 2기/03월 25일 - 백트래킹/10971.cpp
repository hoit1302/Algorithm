#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10;

int n, ans = 1e9;
int cost[SIZE][SIZE];
bool visited[SIZE];

void backTracking(int depth, int cur, int start, int sum) {
    if (depth == n) {
        if (cur == start) {
            ans = min(ans, sum + cost[cur][start]);
        }
        return;
    }
    if (ans <= sum) {
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] || cost[cur][i] == 0) { // 방문 불가
            continue;
        }
        visited[i] = true;
        backTracking(depth + 1, i, start, sum + cost[cur][i]);
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < n; i++) { // 시작점
        backTracking(0, i, i, 0);
    }
    cout << ans;
}