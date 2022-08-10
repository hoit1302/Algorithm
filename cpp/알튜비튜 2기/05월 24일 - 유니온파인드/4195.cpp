#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
 * 친구 네트워크 [#](https://www.acmicpc.net/problem/4195)
 * 문자열 맵으로 저장 + 유니온 파인드
 */
const int MAX = 2e5 + 2;
map<string, int> p;
vector<int> parent;

int findParent(int node) {
    if (parent[node] < 0) return node;
    return parent[node] = findParent(parent[node]);
}

void unionParent(int a, int b) {
    int ap = findParent(a), bp = findParent(b);
    if (ap == bp) return;
    if (abs(parent[ap]) < abs(parent[bp])) { // bp를 루트로
        parent[bp] += parent[ap];
        parent[ap] = bp;
    } else {
        parent[ap] += parent[bp];
        parent[bp] = ap;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc, f;
    string a, b;
    cin >> tc;
    while (tc--) {
        p.clear();
        parent.assign(MAX, -1);
        int idx = 1;
        cin >> f;
        while (f--) {
            cin >> a >> b;
            if (p[a] == 0) {
                p[a] = idx++;
            }
            if (p[b] == 0) {
                p[b] = idx++;
            }
            unionParent(p[a], p[b]);
            cout << -parent[findParent(p[a])] << '\n';
        }
    }
}