#include <iostream>

#define INF 1e9
using namespace std;
int arr[100], dp[10001];

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, a;
    cin >> N >> M;
    fill(dp, dp + M + 1, INF);
    for (int i = 0; i < N; i++) {
        cin >> a;
        arr[i] = a;
        dp[a] = 1;
    }
    for (int i = 1; i <= M; i++) {
        for (int money: arr) {
            if (1 <= i - money)
                dp[i] = min(dp[i], dp[i - money] + 1);
        }
    }
    cout << ((dp[M] < INF) ? dp[M] : -1) << "\n";
    return 0;
}