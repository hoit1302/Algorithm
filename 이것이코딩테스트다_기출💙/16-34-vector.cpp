#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    freopen("../input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 순서를 뒤집어 '최장 증가 부분 수열' 문제로 변환
    reverse(v.begin(), v.end());

    // 다이나믹 프로그래밍을 위한 1차원 DP 테이블 초기화
    int dp[2000];
    fill_n(dp, n, 1);

    // 가장 긴 증가하는 부분 수열(LIS) 알고리즘 수행
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << n - *max_element(dp, dp+n) << "\n";
}