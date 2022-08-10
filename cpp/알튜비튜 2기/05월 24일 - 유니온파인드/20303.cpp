#include <iostream>
#include <vector>

using namespace std;
/*
 * 할로윈의 양아치 [#](https://www.acmicpc.net/problem/20303)
 * 유니온파인드 + 냅색
 */
typedef pair<int, long> ci;
vector<ci> parent; // 아이들의 수, 사탕 수

int findP(int node) {
    if (parent[node].first < 0) return node;
    return parent[node].first = findP(parent[node].first);
}
void unionP(int a, int b) {
    int ap = findP(a), bp = findP(b);
    if (ap == bp) return;
    if (abs(parent[ap].first) < abs(parent[bp].first)) {
        parent[bp].second += parent[ap].second;
        parent[bp].first += parent[ap].first;
        parent[ap].first = bp; // bp를 루트로
    } else {
        parent[ap].second += parent[bp].second;
        parent[ap].first += parent[bp].first;
        parent[bp].first = ap;
    }
}

int knapsack(int limit, int n) {
    vector<long> dp(limit + 1, 0);
    for (int i = 0; i < n; i++) { // 물건을 하나씩 보기
        if (0 <= parent[i].first) continue; // 루트만 탐색
        // cout << parent[i].first << "명이 " << parent[i].second << "개 사탕을 가짐\n";
        for (int j = limit; j >= 1; j--) {
            if (-parent[i].first <= j) { // i번째 물품을 넣을 수 있으면
               dp[j] = max(dp[j], dp[j - (-parent[i].first)] + parent[i].second);
            }
        }
    }
    return dp[limit - 1];
}

int main() {
    int n, m, k, x, y;
    cin >> n >> m >> k;
    parent.assign(n, {-1, 0});
    for (int i = 0; i < n; i++) {
        cin >> parent[i].second;
    }
    while (m--) {
        cin >> x >> y;
        unionP(x - 1, y - 1);
    }
    cout << knapsack(k, n);
}