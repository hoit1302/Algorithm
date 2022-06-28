#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[n] = (너비 1인 타일 채우는 경우의 수 = 1) * dp[n - 1]
 *       + (너비 2인 타일 채우는 경우의 수 = 2) * dp[n - 2]
 */
int fillTile(int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    if (n == 1) {
        return dp[1];
    }
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        dp[i] %= 10007;
    }
    return dp[n];
}

int main() {
    int n;

    cin >> n;

    cout << fillTile(n);
    return 0;
}