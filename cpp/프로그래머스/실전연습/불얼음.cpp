#include <iostream>
#include <vector>

using namespace std;

/*
 * 주요 관점을 불과 얼음이 아닌 "각 칸들이 받는 영향"으로 바꾸어 생각
 * 격자 사이즈 n은 최대 30 x 30으로 굉장히 작고 흐르는 시간인 t는 10억으로 굉장히 크기 때문
 * O(N^3), N = 30 (불과 얼음은 각 최대 30개라서)
 */
vector<vector<int>> solution(int n, int t, vector<vector<int>> fires, vector<vector<int>> ices) {
    vector<vector<int> > g(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto fpos: fires) { // 1. 불
                // 불 영향 시작 시간
                int fs = max(abs(fpos[0] - 1 - i), abs(fpos[1] - 1 - j));
                if (i == fpos[0] - 1 && j == fpos[1] - 1) fs = 1;
                if (t < fs) continue;
                g[i][j] += (t - fs + 1);
            }
            for (auto ipos: ices) { // 2. 얼음
                // 얼음 영향 시작 시간
                int is = abs(i - (ipos[0] - 1)) + abs(j - (ipos[1] - 1));
                if (i == ipos[0] - 1 && j == ipos[1] - 1) is = 1;
                if (t < is) continue;
                g[i][j] -= (t - is + 1);
            }
        }
    }
    return g;
}

// 결과 확인용
void print(int n, vector<vector<int>> g) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << ' ';
        } cout << '\n';
    }
}
int main() {
//    print(3, solution(3, 2, {{1, 1}}, {{3, 3}}));
//    print(5, solution(5, 3, {{5, 5}, {1, 3}, {5, 2}}, {{1, 5}, {3, 2}}));
//     solution(30, 1000000000, {{1, 1}, {15, 15}}, {{7, 7}, {23, 28}});
}