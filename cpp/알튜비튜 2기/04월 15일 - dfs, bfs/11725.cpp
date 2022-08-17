#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 100001;
int ans[SIZE] = {0,};
vector<vector<int>> tree;

void dfs(int root) {
    for (int i = 0; i < tree[root].size(); i++) {
        int nxt = tree[root][i];
        if (ans[nxt]) {
            continue;
        }
        ans[nxt] = root;
        dfs(nxt);
    }
}

int main() {
    int n, a, b;
    cin >> n;
    tree.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}