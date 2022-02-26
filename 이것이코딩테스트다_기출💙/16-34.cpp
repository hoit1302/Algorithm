#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[2001] = {0,};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

//    int array[10] = {0,}; -> 모든 원소 0으로 초기화됨.
//    int array[10] = {1,}; -> 0번째 원소만 1이고 나머지는 0으로 초기화됨.
    int dp[2001];
    fill_n(dp, n, 1); // 초기화 중요!

//    가장 긴 감소하는 부분 수열 알고리즘 수행, 가장 긴 증가하는 부분 수열 알고리즘은 부호만 < 로 바꿔주면 됨.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    // result
    // *max_element(dp, dp+n) 잘 활용하기
    cout << n - *max_element(dp, dp+n) << "\n";
}
