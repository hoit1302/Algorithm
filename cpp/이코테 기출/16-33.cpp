#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    freopen("../input.txt", "r", stdin);
    int n;
    cin >> n;
    int day[16] = {0,}, pay[16] = {0,};
    for (int i = 1; i <= n; i++) {
        cin >> day[i] >> pay[i];
    }

    // dp: 역순, 누적 최대 이익
    // (현재 이 일을 안해도 됨. 1. 기간이 넘어서 못할 수 있고, 2. 4일째가 되어도 5일째 일하고 4일째는 쉬는 것이 이득인 경우가 있음)
    int max_value = 0, dp[17] = {0,};
    for (int i = n; i >= 1; i--) {
        int possible_day = i + day[i]; // 이 날"부터" 새로운 일 가능
        if (possible_day > n + 1) {
            dp[i] = max_value;
            continue;
        }
        dp[i] = max(max_value, pay[i] + dp[possible_day]);
        max_value = dp[i];
    }
    cout << max_value << "\n";
    return 0;
}