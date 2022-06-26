#include <iostream>
#include <vector>

using namespace std;


int n, res = 0;
vector<vector<bool>> visited;

void go(int r) {
    if (r == n) {
        res++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (visited[0][c] || visited[1][r - c + n - 1] || visited[2][r + c])
            continue;
        visited[0][c] = visited[1][r - c + n - 1] = visited[2][r + c] = true;
        go(r + 1);
        visited[0][c] = visited[1][r - c + n - 1] = visited[2][r + c] = false;
    }
}

int main() {
    cin >> n;
    visited.assign(3, vector<bool>(n * 2 - 1, false));
    go(0);
    cout << res << '\n';
}