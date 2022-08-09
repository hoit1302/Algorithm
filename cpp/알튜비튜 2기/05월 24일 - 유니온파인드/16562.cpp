#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int a) {
    if (parent[a] < 0) {
        return a;
    } return parent[a] = findParent(parent[a]);
}
void unionParent(int a, int b) {
    int ap = findParent(a), bp = findParent(b);

    if (ap == bp) {
        return;
    }
    if (parent[ap] < parent[bp]) { // a의 비용이 더 크다. b를 루트로
        parent[ap] = bp;
    } else {
        parent[bp] = ap;
    }
}

//void printParent() {
//    for (int a: parent) {
//        cout << a << ' ';
//    } cout << '\n';
//}
int main() {
    int n, m, k, a, b;
    cin >> n >> m >> k;
    parent.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        parent[i] = -a;
    }
//    printParent();
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        unionParent(a - 1, b - 1);
//        printParent();
    }
    int ans = 0;
    for (int c : parent) {
        if (c < 0) {
            ans -= c;
        }
    }
    if (ans <= k) {
        cout << ans;
    } else {
        cout << "Oh no";
    }
}