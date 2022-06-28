#include <iostream>
#include <vector>

using namespace std;

int pay(int n, int m, vector<int> &coin) {
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= m; j++) {
            // dp[i] = 주어진 동전 종류를 사용해서 i원을 만드는 경우의 수
            dp[j] += dp[j - coin[i]]; // 해당 동전을 사용하기 전 금액의 경우의 수와 현재 경우의 수를 더함
        }
    }
    return dp[m];
}

int main() {
    int t, n, m;

    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> coin(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> coin[i];
        }
        cin >> m;

        cout << pay(n, m, coin) << '\n';
    }
    return 0;
} 