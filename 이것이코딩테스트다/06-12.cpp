#include <iostream>
#include <vector>
#include <algorithm>

#define name first
#define score second
using namespace std;

// p. 182: 두 배열의 원소 교체
bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.score < b.score;
}

int main() {
    freopen("../input.txt", "r", stdin);
    int N, K, a;
    long long res = 0LL;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> a;
        A[i] = a;
    }
    for (int i = 0; i < N; i++) {
        cin >> a;
        B[i] = a;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < K; i++) {
        if (A[i] < B[N - 1 - i])
            A[i] = B[N - 1 - i];
    }
    for (int i = 0; i < N; i++)
        res += A[i];
    cout << res << "\n";
    return 0;
}
