#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAX = 4e6;
bool is_prime[MAX + 1];
vector<int> primes;

void eratosthenes() {
    fill(is_prime, is_prime + MAX + 1, true); // true 소수이다.
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i]) continue;
        // 소수이면 배수에 대해서 지우기
        for (ll j = i * i; j <= MAX; j += i) {
            is_prime[j] = false;
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    int n, ans = 0;
    cin >> n;
    eratosthenes();
    int s = 0, e, p_n = primes.size(), tmp_sum;
    // primes[p_n-1]: 3999971
    while (s < p_n) {
        if (n < primes[s] || s == p_n-1 && primes[s] < n) {
            break;
        }
        tmp_sum = 0;
        for (e = s; e < p_n; e++) {
            tmp_sum += primes[e];
            if (n <= tmp_sum) {
                if (tmp_sum == n) {
                    // cout << primes[s] << ' ' << primes[e] << '\n';
                    ans++;
                }
                s++;
                break;
            }
        }
    }
    cout << ans << '\n';
}