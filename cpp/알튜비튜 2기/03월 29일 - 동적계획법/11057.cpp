#include <iostream>

using namespace std;
const int SIZE = 1002; // 3자리 오르막 수의 개수 == 4자리 오르막 수 중 마지막이 9로 끝나는 수의 개수와 동일 (누적합)
int dp[SIZE][10];

void runDp() {
    // 1자리 수들은 각 idx로 끝나는 수가 1개임.
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }
    // i자리 수들 중 j값으로 끝나는 숫자를 dp[i][j]개만큼 가지고 있다.
    for (int i = 2; i < SIZE; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][0] = 1;
                continue;
            }
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
        }
    }

}

int main() {
    runDp();
    int n;
    cin >> n;
    cout << dp[n+1][9] << '\n';
}