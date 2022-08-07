#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10;

int n, ans = 1e9;
int cost[SIZE][SIZE];
bool visited[SIZE];

void backTracking(int depth, int cur, int sum) {
    if (depth == n) {
        if (cost[cur][0] != 0) { // 길이 없을 수도 있음.
            ans = min(ans, sum + cost[cur][0]);
        }
        return;
    }
    // 가지치기: 이미 값이 더 큼
    if (ans <= sum) {
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] || cost[cur][i] == 0) { // 방문 불가
            continue;
        }
        visited[i] = true;
        backTracking(depth + 1, i, sum + cost[cur][i]);
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
    visited[0] = true; // 시작점 0번으로 고정
    backTracking(1, 0, 0);
    cout << ans;
}
