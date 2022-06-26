#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
vector<bool> visited;

void go(int depth, string seq) {
    if (depth == m) {
        cout << seq << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        go(depth + 1, seq + to_string(i) + " ");
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    visited.assign(n + 1, false);
    go(0, "");
}