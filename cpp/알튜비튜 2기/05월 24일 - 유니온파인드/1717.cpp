#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) {
    if (parent[node] < 0) {
        return node; //값이 음수면 루트 정점
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

void unionInput(int x, int y) {
    int xp = findParent(x), yp = findParent(y);

    if (xp == yp) { //이미 같은 집합에 있는 경우
        return;
    }
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cmd, a, b;

    cin >> n >> m;
    parent.assign(n + 1, -1);
    while (m--) {
        cin >> cmd >> a >> b;

        if (!cmd) {
            unionInput(a, b);
        } else { // 같은 집합인지 확인
            if (findParent(a) == findParent(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}