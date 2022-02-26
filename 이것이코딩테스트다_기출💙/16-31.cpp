#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen( "../input.txt", "r", stdin);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;
        int arr[20][20] = {0, };
        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        int res;
        int dp[20][20] = {0, };
        // init
        for (int i = 0; i < n; i++)
            dp[i][0] = arr[i][0];
        // algorithm, 구현 방식이 기존에 내가 풀던 방식과 다름!
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                int up = 0, mid = 0, down = 0;

                if (i == 0) up = 0;
                else up = dp[i-1][j-1];

                if (i == n-1) down = 0;
                else down = dp[i+1][j-1];

                mid = dp[i][j-1];

                dp[i][j] = arr[i][j] + max({up, mid, down});
            }
        }
        // result
        int max = 0;
        for (int i = 0 ; i < n;i++) {
            max = (dp[i][m-1] > max) ? dp[i][m-1] : max;
        }
        cout << max << "\n";
        }
    return 0;
}

// input data
/*
2
3 4
1 3 3 2 2 1 4 1 0 6 4 7
4 4
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
*/