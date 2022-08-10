#include <iostream>
#include <vector>

using namespace std;
/*
 * 사이클 게임 [#] (https://www.acmicpc.net/problem/20040)
 */
vector<int> parent;

int findParent(int node) {
    if (parent[node] < 0) return node;
    return parent[node] = findParent(parent[node]);
}
void unionParent(int a, int b) {
    int ap = findParent(a), bp = findParent(b);
    if (ap == bp) return;
    if (abs(parent[ap]) < abs(parent[bp])) { // bp가 루트
        parent[bp] += parent[ap];
        parent[ap] = bp;
    } else {
        parent[ap] += parent[bp];
        parent[bp] = ap;
    }
}
int main() {
    int n, m, a, b, cycle = 0;
    cin >> n >> m;
    parent.assign(n, -1);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (!cycle && findParent(a) == findParent(b)) {
            cycle = i;
        } else {
            unionParent(a, b);
        }
    } cout << cycle;
}