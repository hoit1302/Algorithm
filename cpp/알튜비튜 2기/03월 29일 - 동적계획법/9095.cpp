#include <iostream>
#include <vector>

using namespace std;

//top-down 방식 dp
vector<int> dp_top;

int numberOfCasesTop(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return dp_top[0] = 1;
    }
    if (dp_top[n]) {
        return dp_top[n];
    }
    for (int i = 1; i <= 3; i++) {
        dp_top[n] += numberOfCasesTop(n - i);
    }
    return dp_top[n];
}

//bottom-up 방식 dp
int numberOfCases(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main() {
    int t, n;

    //입력
    cin >> t;
    while (t--) {
        cin >> n;

        //연산 & 출력
        //bottom-up 방식
        //cout << numberOfCases(n) << '\n';
        //top-down 방식
        dp_top.assign(n + 1, 0);
        cout << numberOfCasesTop(n) << '\n';
    }
    return 0;
}