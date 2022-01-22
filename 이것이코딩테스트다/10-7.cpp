#include <iostream>
#include <vector>

using namespace std;

// p. 298: 팀 결성
// 유니온 파인트

int parent[100001];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return i;
}

void union_(int i, int j) {
    int a = find(i), b = find(j);
    if (a < b) parent[j] = i;
    else parent[i] = j;
}

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, cal, a, b;
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
        parent[i] = i;
    for (int i = 0; i < M; i++) {
        cin >> cal >> a >> b;
        if (cal == 0)
            union_(a, b);
        else {
            cout << (find(a) == find(b) ? "YES" : "NO") << "\n";
        }
    }
}