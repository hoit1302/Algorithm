#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
set<string> s;
vector<int> v;
vector<bool> visited;

void go(int depth, string str) {
    if (depth == m) {
        cout << str << '\n';
        return;
    }
    int bef = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && bef != v[i]) {
            bef = v[i];
            visited[i] = true;
            go(depth + 1, str + to_string(v[i]) + " ");
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    v.assign(n, 0);
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    go(0, "");
    for (string sq: s) {
        cout << sq << '\n';
    }
}