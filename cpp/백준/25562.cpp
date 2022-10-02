#include <iostream>
#include <cmath>

using namespace std;

int max_cnt[31];
/*
 * SUAPC 2022 summer F번
 */
int main() {
    int n;
    cin >> n;
    max_cnt[2] = 1;
    for (int i = 3; i <= n; i++) {
        max_cnt[i] = max_cnt[i-1] + i - 1;
    }
    cout << max_cnt[n] << '\n'; // 서로 다른 차의 개수의 최댓값
    for (int i = 1; i <= pow(2, n - 1); i *= 2) { // 배열 출력
        cout << i << ' ';
    } cout << '\n';
    cout << n - 1 << '\n'; // 서로 다른 차의 개수의 최솟값
    for (int i = 1; i <= n; i++) { // 배열 출력
        cout << i << ' ';
    } cout << '\n';
}