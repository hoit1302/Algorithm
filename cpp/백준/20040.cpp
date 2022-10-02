#include <iostream>
using namespace std;

int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
bool findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    return a == b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, result = 0;
    cin >> n >> m;
    int* parent = new int[n+1];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (findParent(parent, a, b)) {
            result = i;
            break;
        } else {
            unionParent(parent, a, b);
        }
    }
    cout << result << "\n";
}
