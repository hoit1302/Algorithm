#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// p. 300: 도시 분할 계획
// 최소 신장 트리 -> 간선 정보 정렬 후 사이클이 생기지 않도록 union
// 한 번의 union 계산만다 도시의 수가 -1씩 되는 것이 맞나?
int parent[100001];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return i;
}

void union_(int i, int j) {
    int a = find(i), b = find(j);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, A, B, C;
    cin >> N >> M;

    vector<pair<int, pair<int, int> > > e;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        e.push_back({C, {A, B}});
    }
    sort(e.begin(), e.end());

    int res = 0, last;
    for (int i = 0; i < M; i++) {
        auto cur = e[i];
        int cur_cost = cur.first, cur_A = cur.second.first, cur_B = cur.second.second;
        if (find(cur_A) != find(cur_B)) {
            N--;
            union_(cur_A, cur_B);
            res += cur_cost;
            last = cur_cost;
        }
    }
    cout << res - last << "\n";
}