#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX = 1e5 + 1;
vector<int> primes(MAX); // -1, -1, 2, 3, 2, 5, 2, 7, ...
map<int, int> exponent;

void calEratos() {
    primes[0] = primes[1] = -1;
    for (int i = 2; i < MAX; i++) {
        primes[i] = i;
    }

    for (int i = 2; i * i <= MAX; i++) { // sqrt(MAX) 까지
        if (primes[i] != i) continue; // 소수가 아님
        for (int j = i * i; j < MAX; j += i) { // 소수인 수에 대해서
            if (primes[j] == j) // 아직 갱신되지 않은 경우에만
                primes[j] = i; // 갱신
        }
    }
}

void countExponent(int num, int sign) {
    while (num != 1) {
        exponent[primes[num]] += sign;
        num /= primes[num];
    }
}

bool isR() {
    for (auto & iter : exponent) {
        // cout << iter.first << ' ' << iter.second << '\n';
        if (iter.second < 0) {
            return true;
        }
    } return false;
}

int main() {
    int n, a;
    char c;

    calEratos();

    cin >> n;
    cin >> a; //처음 수 미리 입력

    if (a == 0) {
        cout << "mint chocolate\n";
        return 0;
    }
    countExponent(abs(a), 1); // 곱셈

    for (int i = 1; i < n; i++) {
        cin >> c >> a;

        if (a == 0) {
            cout << "mint chocolate\n";
            return 0;
        }

        if (c == '*') { // 곱셈, 지수 증가
            countExponent(abs(a), 1);
        } else { // 나눗셈, 지수 감소
            countExponent(abs(a), -1);
        }
    }

    if (isR()) cout << "toothpaste\n";
    else cout << "mint chocolate\n";
}