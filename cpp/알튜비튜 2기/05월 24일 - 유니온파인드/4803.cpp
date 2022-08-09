#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, cycle;

int findParent(int a) {
    if (parent[a] < 0) {
        return a;
    } return parent[a] = findParent(parent[a]);
}
void unionParent(int a, int b) {
    int ap = findParent(a), bp = findParent(b);
    if (ap == bp) {
        cycle[ap] = true;
        return;
    }
    if (cycle[ap] || cycle[bp]) { //사이클이 있는 집합이라면
        cycle[ap] = cycle[bp] = true;
    }
    if (parent[ap] < parent[bp]) { // ap의 절댓값이 더 큼. ap를 루트로
        parent[ap] += parent[bp];
        parent[bp] = ap;
    } else {
        parent[bp] += parent[ap];
        parent[ap] = bp;
    }
}
int findTreeCnt(int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!cycle[i] && parent[i] < 0) {
            cnt++;
        }
    } return cnt;
}
int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m, a, b, o = 1;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            return 0;
        }
        parent.assign(n, -1); // 초기화: 모두 부모
        cycle.assign(n, false);
        for (int i = 0; i < m; i++) { // 합집합 연산
            cin >> a >> b;
            unionParent(a - 1, b - 1);
        }
        // 출력
        int cnt = findTreeCnt(n);
        cout << "Case " << o++ << ": ";
        if (!cnt) {
            cout << "No trees.\n";
        } else if (cnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << cnt << " trees.\n";
        }
    }
}