#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int INF = 1e9, SIZE = 152;
int dp[152][152]; // 150 + 1(idx 0) + 1 (dp 수행 시 + 1)

int solution(int alp, int cop, vector<vector<int>> proms) {
    // 1. 알고력 최댓값과 코딩력 최댓값 구하기 (목표)
    int a_max = 0, c_max = 0;
    for (vector<int> p: proms) {
        a_max = max(a_max, p[0]);
        c_max = max(c_max, p[1]);
    }
    if (a_max <= alp && c_max <= cop) return 0; // 가지치기
    alp = min(a_max, alp);
    cop = min(c_max, cop);
    // 2. dp 배열 초기화
    for (int i = alp; i <= a_max; i++) for (int j = cop; j <= c_max; j++) {
            dp[i][j] = INF;
        }
    dp[alp][cop] = 0;
    // 3. i 알고력과 j 코딩력을 가질 수 있는 최단시간을 dp 배열에 저장하도록 갱신
    for (int i = alp; i <= a_max; i++) for (int j = cop; j <= c_max; j++) {

            dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]); // 3-1

            dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]); // 3-2

            // 3-3, 목표치를 넘을 경우 목표 칸에 저장해 혼동 줄이기
            for (vector<int> p: proms) {
                int a_rq = p[0], c_rq = p[1], a_rw = p[2], c_rw = p[3], cost = p[4];
                if (i < a_rq || j < c_rq) continue;
                if (a_max < i + a_rw && c_max < j + c_rw) {
                    dp[a_max][c_max] = min(dp[a_max][c_max], dp[i][j] + cost);
                } else if (a_max < i + a_rw) {
                    dp[a_max][j + c_rw] = min(dp[a_max][j + c_rw], dp[i][j] + cost);
                } else if (c_max < j + c_rw) {
                    dp[i + a_rw][c_max] = min(dp[i + a_rw][c_max], dp[i][j] + cost);
                } else {
                    dp[i + a_rw][j + c_rw] = min(dp[i][j] + cost, dp[i + a_rw][j + c_rw]);
                }
            }
        }
    return dp[a_max][c_max]; // 4. 정답 리턴
}
