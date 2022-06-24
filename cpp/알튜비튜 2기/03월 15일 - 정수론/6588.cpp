#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e6 + 1;
vector<bool> prime(MAX, true); // true: 소수이다

void eratosthenes() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!prime[i]) continue; // 소수 아니면
        for (int j = i * i; j < MAX; j += i) {
            prime[j] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    eratosthenes();
    int n;
    while (cin >> n) {
        if (n == 0) break;

        bool is_exist = false;
        for (int i = 3; i <= n / 2; i+=2) {
            if (prime[i] && prime[n - i]) {
                is_exist = true;
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
        if (!is_exist) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}
