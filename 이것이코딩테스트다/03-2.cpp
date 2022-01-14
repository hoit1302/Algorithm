#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, K, a, b, m, res = 0;
    cin >> N >> M >> K;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    a = v[N - 1];
    b = v[N - 2];
    m = M; // m: 남은 연산 가능 횟수
    cout << a << " " << b << "\n";
    for (int i = 0; i < M; i++) {
        if (m == 0) break;
        if (!(i % 2)) { // 짝수
            if (m < K) {
                res += m * a;
                m = 0;
                break;
            }
            res += K * a;
            m -= K;
        } else { // 홀수
            res += b;
            m--;
        }
        cout << res << "\n";
    }
    cout << res << "\n";
    return 0;
}

// 하지만 가장 큰 수를 더하는 횟수를 구해서 더 간결하게 구할 수 있음 !!!
// (직접 계산해봄)
// max_count = (M / (K+1)) * K + M % (K+1)
// max_sec_count = M - max_count