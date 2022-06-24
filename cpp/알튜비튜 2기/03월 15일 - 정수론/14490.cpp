#include <iostream>

using namespace std;

int calGcd(int a, int b) { // a < b 전제
    if (a == 0) {
        return b;
    }
    return calGcd(b % a, a);
}

int main() {
    int n, m, gcd;
    string input;
    cin >> input;
    n = stoi(input.substr(0, input.find(':')));
    m = stoi(input.substr(input.find(':') + 1));
    gcd = calGcd(min(n, m), max(n, m));
    cout << n / gcd << ':' << m / gcd << '\n';
}