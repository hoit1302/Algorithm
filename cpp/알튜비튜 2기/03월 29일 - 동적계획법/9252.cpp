#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1e3;
string s1, s2;
vector<vector<int>> dp;

int lcs() {
    int len1 = s1.size(), len2 = s2.size();
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
//    for (int i = 1; i <= len1; i++) {
//        for (int j = 1; j <= len2; j++) {
//            cout << dp[i][j] << ' ';
//        } cout << '\n';
//    }

    return dp[len1][len2];
}

void printStr(int i, int j) {
    if (dp[i][j] == 0) return;
    if (s1[i - 1] == s2[j - 1]) {
        printStr(i - 1, j - 1);
        cout << s1[i - 1];
    } else dp[i - 1][j] > dp[i][j - 1] ? printStr(i - 1, j) : printStr(i, j - 1);
}

int main() {
    cin >> s1 >> s2;
    dp.assign(SIZE + 1, vector<int>(SIZE + 1, 0));
    int ans = lcs();
    cout << ans << '\n';
    if (ans) {
        printStr(s1.size(), s2.size());
    }
}
