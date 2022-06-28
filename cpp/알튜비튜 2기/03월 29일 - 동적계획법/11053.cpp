#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lisAdv(int n, vector<int> &arr) {
    int cnt = 0;
    vector<int> dp(n + 1, 0); // dp[1]을 갱신하기 위해 dp[0] = 0으로 설정
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = idx; j >= 0; j--) {
            if (arr[i] > dp[j]) { // 증가하는 관계라면
                dp[j + 1] = arr[i];
                cnt++;
                if (j == idx) { // 최장 길이 갱신
                    idx++;
                }
                break;
            }
        }
    }

    cout << cnt << '\n';
    return idx;
}

int lis_tuti(int n, vector<int> &seq) {
    int cnt = 0;
    int answer = 1;
    vector<int> dp(n, 0);

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (seq[i] > seq[j] && dp[j] > temp) {
                temp = dp[j];
                cnt++;
            }
        }
        dp[i] = temp + 1;
        answer = max(answer, dp[i]);
    }
    cout << cnt << '\n';
    return answer;
}

int lis(int n, vector<int> &v) {
    int res = 1, cnt = 0;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                cnt++;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << cnt << '\n';
    return res;
}

// adv, binary_search 풀이가 추가로 더 있음.


int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << lisAdv(n, v) << '\n';
    cout << lis_tuti(n, v) << '\n';
    cout << lis(n, v) << '\n';
}