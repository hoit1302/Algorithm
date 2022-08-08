#include<iostream>
#include <cstring>

using namespace std;
/*
 * 외판원 순회 [#](https://www.acmicpc.net/problem/2098)
 * dp (재귀함수로, memoization)을 매우 어려워하는 나에게 가혹한 문제
 * dfs 탐색 순서가 곧 cost 배열 갱신 순서인데 이해하는데 오래 걸림
 * dfs 함수에 대한 모호한 이해
 * 생소한 비트마스킹
 * 막상 코드를 읽으면 꼬인 것 없이 깔끔한 형태이지만 코드를 쓱 보면서 안 읽힌다.
 */
const int MAX = 16;
const int INF = 987654321;
int n, answer_bit;
int map[MAX][MAX];
int cost[MAX][1 << MAX];
// [1][00110] = c: 현재 1번 정점이고 2번과 1번 도시를 방문을 한 상태일 때, 지금까지의 최소비용은 c원
// dfs 함수 호출값을 저장해두는 것과 동일함.
// 같은 parameter로 호출했을 땐 그 정보를 저장해두고 있다가 바로 return 해줌.

// cur_bit가 나타내는 도시를 방문했고 현재 cur_node에 있을 때, 나머지에 대해 끝까지 순회했을 때의 최소 비용은?
int dfs(int cur_node, int cur_bit) {
        // 1. 종료조건: 모두 방문했으면
        if (cur_bit == answer_bit) {
        if (map[cur_node][0] != 0) { // 길이 없을 수도 있음.
            return map[cur_node][0];
        } return INF;
    }
    // 2. 이미 최솟값으로 갱신이 되었다면 바로 memoization된 값을 반환
    if (cost[cur_node][cur_bit] != -1) return cost[cur_node][cur_bit];

    // 3. 갱신시키기
    cost[cur_node][cur_bit] = INF; // 3-1. 초기화
    for (int i = 0; i < n; i++) {
        // 3-2. cur_node에서 i로 못 가는 경우 거르기
        if (map[cur_node][i] == 0) continue;
        if ((cur_bit & (1 << i)) == (1 << i)) continue;
        // 3-3. 최솟값 갱신
        cost[cur_node][cur_bit] = min(cost[cur_node][cur_bit],
                                      map[cur_node][i] + dfs(i, cur_bit | 1 << i));
    }
//    cout << cur_node << ' ' << cur_bit << ' ' << cost[cur_node][cur_bit] << '\n';
    return cost[cur_node][cur_bit];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j]; // 비용 행렬
        }
    }
    answer_bit = (1 << n) - 1;
    memset(cost, -1, sizeof(cost)); // cstring
    cout << dfs(0, 1) << '\n'; // cost[0][0001] 값 출력

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 1 << n; j++) {
//            cout << cost[i][j] << ' ';
//        } cout << '\n';
//    }
    return 0;
}
