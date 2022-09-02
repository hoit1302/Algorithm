#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tp;
vector<int> parent(1e5 + 1, -1);

int findParent(int a) {
    if (parent[a] < 0) return a;
    return parent[a] = findParent(parent[a]);
}
bool unionParent(int a, int b) {
    int ap = findParent(a), bp = findParent(b);
    if (ap == bp) return false; // 이미 같은데 붙이면 사이클 형성, 안됨.
    if (abs(parent[ap]) < abs(parent[bp])) { // bp를 루트로
        parent[bp] += parent[ap];
        parent[ap] = bp;
    } else {
        parent[ap] += parent[bp];
        parent[bp] = ap;
    }
    return true;
}
int kruskal(int v, vector<tp> &edges) {
    ll ans = 0;
    int cnt = 0;
    for (auto [cost, a, b]: edges) {
        if (unionParent(a, b)) { // 성공했으면
            ans += cost;
            cnt++;
        }
        if (cnt == v - 1)
            return ans;
    }
    return 0;
}
int main() {
    int v, e, a, b, c;
    cin >> v >> e;
    vector<tp> edges(e);
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }
    sort(edges.begin(), edges.end());
    cout << kruskal(v, edges);
}