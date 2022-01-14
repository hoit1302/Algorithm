#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    int N, K, res = 0;
    cin >> N >> K;
    while (true) {
        // N < K일 경우 바로 아래 if문을 계속 타며 무한 루프에 빠질 수 있음.
        if (N == 1 || N < K) break;
        // 나누어 떨어지지 않아서 나누어 떨어지는 숫자까지 1씩 빼기
        if (N % K) {
            int minus = N - (N / K) * K;
            N -= minus;
            res += minus;
        } else { // 나누어 떨어짐 > 나눗셈
            N /= K;
            res++;
        }
    }
    res += N - 1;
    cout << res << "\n";
    return 0;
}
