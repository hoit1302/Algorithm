#include <iostream>
// epper 상 1
#include <vector>
#include <algorithm>
using namespace std;

#define max(x, y) (x) > (y) ? (x) : (y)
long long solution(int N, vector<vector<long long>> money) {
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                money[i][j] += money[i - 1][0];
            else if (j == i)
                money[i][j] += money[i - 1][j - 1];
            else
                money[i][j] += max(money[i - 1][j - 1], money[i - 1][j]);
        }
    }
    // 맨 아랫줄에 저장된 값 중 가장 큰 값 반환
    return *max_element(money[N - 1].begin(), money[N-1].end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<vector<long long>> money;
    for (int i = 0; i < N; i++) {
        money.push_back(vector<long long>(i + 1, 0));
        for (int j = 0; j <= i; j++) {
            cin >> money[i][j];
        }
    }
    cout << solution(N, money) << "\n";
    return 0;
}