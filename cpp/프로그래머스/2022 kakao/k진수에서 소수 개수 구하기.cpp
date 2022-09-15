#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

string k_ary;
void changeK(int n, int k) {
    while (n / k != 0) {
        k_ary.append(to_string(n % k));
        n = n / k;
    }
    k_ary.append(to_string(n % k));
    reverse(k_ary.begin(), k_ary.end());
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int solution(int n, int k) {
    changeK(n, k); // 1. k진수로 변환하기
    // 2. 문자열 관점으로 소수 개수 구하기
    int cnt = 0;
    string num;
    for (int i = 0; i < k_ary.size(); i++) {
        if (k_ary[i] != '0') {
            num.append(1, k_ary[i]);
            continue;
        }
        // 0임
        if (!num.empty()) {
            if (isPrime(stol(num))) {
                cnt++;
            }
        }
        num = "";
    }
    if (!num.empty()) { // 마지막 남은 문자열 처리
        if (isPrime(stol(num))) {
            cnt++;
        }
    }
    return cnt;
}