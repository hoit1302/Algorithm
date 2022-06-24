#include <iostream>
#include <cmath>

using namespace std;
typedef pair<int, int> ci;

int calGcd(int a, int b) { // a < b
    if (a == 0)
        return b;
    return calGcd(b % a, a);
}

int main() {
    int gcd, lcm;
    cin >> gcd >> lcm;

    ci res;
    int mul = lcm / gcd, min_value = 1e8;
    for (int i = (int) sqrt(mul); i >= 1; i--) {
        if (mul % i != 0) continue;

        long a = gcd * i, b = gcd * (mul / i);
        if (a + b < min_value && calGcd(a, b) == gcd) {
            res = {a, b};
            min_value = a + b;
        }
    }
    cout << res.first << ' ' << res.second << '\n';
}