#include <iostream>
#include <vector>
using namespace std;

/*
 * 등수 구하기 [#](https://www.acmicpc.net/problem/1205)
 *
 * 문제 설명: 위에서 몇번째?, 동일 점수, 가장 작은(좋은) 등수
 * 예전에 처음 풀 때 못 풀어냈다가 다시 꺼내서 풀어봤음.
 * 틀린 이유: 코너 케이스는 처음부터 완벽히 처리했는데, 핵심 로직을 잘못 이해했음
 *
 * "같은 점수가 있을 때는 그러한 점수의 등수 중에 가장 작은 등수가 된다." 이 조건에만 정신 팔려서
 * 같은 점수 이후에는 랭크를 다시 랭킹 리스트에서 몇 번째인지로 따져야하는데 여러 같은 점수들을 1개로 묶어버렸었음.
 */

int findRank(int s_size, vector<int> ss, int tasu) {
    int rank = -1;
    // 1. 랭킹 리스트에 오를 수 없는 경우:
    // 랭킹 리스트가 꽉 차있을 때, 새 점수가 이전 점수보다 더 좋을 때만 점수가 바뀐다.
    if (tasu <= ss[s_size - 1]) {
        return rank;
    }
    // 2. 랭킹 리스트에 들 수 있으므로 자신의 랭킹 찾기
    rank = 1;
    int bef = ss[0]; // p는 10보다 큼.
    if (tasu >= bef) { // 2-1. 1등
        return rank;
    }
    // 2-2. 2등 ~ 꼴등
    for (int i = 1; i < s_size; i++) {
        if (bef != ss[i]) {
            rank = i + 1;
        } bef = ss[i];
        if (tasu >= ss[i]) {
            return rank;
        }
    }
}

int main() {
    int n, tasu, p;
    cin >> n >> tasu >> p;
    vector<int> scores(p, -1); // p: 랭킹 리스트 사이즈
    for (int i = 0; i < n; i++) { // n: 입력, 0 <= n <= p
        cin >> scores[i];
    }
    cout << findRank(p, scores, tasu);
}