#include <vector>
using namespace std;

int arr[1001][2]; // 2번째 0: 2^n으로 정해진 배열 용량, 원소 수

int solution(vector<vector<int>> queries) {
    int ans = 0;
    for (int i = 0; i < 1001; i++) { // 각 배열의 기본 용량: 1 (idea)
        arr[i][0] = 1;
    }
    for (auto query: queries) {
        int arr_n = query[0];

        int cnt = arr[arr_n][1], cap = arr[arr_n][0]; // 기존
        int nxt = query[1] + cnt, n_cap = cap; // 갱신

        while (n_cap < nxt) { // -> 이런 부분을 짜기 어려워함.
            n_cap *= 2;
        }
        // nxt: 6일 때 n_cap이 (1<6 → 2<6 → 4<6 →) 8이 되었을 때 멈춤

        if (cap != n_cap)
            ans += cnt;

        arr[arr_n][0] = nxt;
        arr[arr_n][1] = n_cap;
    }
    return ans;
}