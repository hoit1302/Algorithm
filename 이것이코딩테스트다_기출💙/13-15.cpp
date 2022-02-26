#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 모든 간선의 비용이 동일할 때는 BFS를 사용하여 최단거리를 찾을 수 있다!
vector<int> graph[300001];
vector<int> cost(300001, -1); // array로 구현하면 메모리 초과... 왜 벡터가 더 메모리를 적게 쓰는가?

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    queue<int> q;
    // 초기화
    cost[X] = 0;
    q.push(X);

    // 알고리즘
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt: graph[cur]) {
            if (cost[nxt] == -1) { // 갱신 필요함.
                cost[nxt] = cost[cur] + 1;
                if (cost[nxt] < K)
                    q.push(nxt);
            }
        }
    }

    // result
    bool flag = false;
    for (int i = 1; i <= N; i++) {
        if (cost[i] == K) {
            cout << i << "\n";
            flag = true;
        }
    }
    if (!flag)
        cout << "-1" << "\n";
    return 0;
}