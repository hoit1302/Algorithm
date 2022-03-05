#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, res = 0;
bool visited[8001];
vector<int> v;

void dfs(int depth, int value, int idx) {
    if (depth == 3) {
        if (2000 <= value && value <= 2500) {
            res++;
        }
        return;
    }
    for (int i = idx; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(depth + 1, value + v[i], i + 1);
            visited[i] = false;
        }
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    dfs(0, 0, 0);
    cout << res << '\n';
    return 0;
}
