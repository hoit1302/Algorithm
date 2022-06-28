#include <iostream>
#include <vector>

using namespace std;

//LCS 길이 구하는 함수
int lcs(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            } else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    return dp[n][m];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << lcs(str1, str2);
    return 0;
} 