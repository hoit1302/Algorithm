#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 5e6 + 1;
vector<int> prime; // 소수면 0, 소수가 아니면 소인수 중 가장 작은 숫자

void eratosthenes() {
    prime[0] = prime[1] = -1;
    prime.assign(MAX, 0);
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) continue; // 이미 방문했음, 소수가 아님
        for (long j = i * i; j < MAX; j += i) {
            if (prime[j]) continue; // 이미 방문해 최솟값이 쓰였음.
            prime[j] = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    eratosthenes();

    int n, k;
    vector<int> ans;
    cin >> n;
    while (n--) {
        cin >> k;

        while (prime[k]) {
            cout << prime[k] << ' ';
            k /= prime[k];
        }
        cout << k << '\n';
    }
}