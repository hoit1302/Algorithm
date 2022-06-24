#include <iostream>

using namespace std;

// O(n)으로 연산
int gcdLoop(int a, int b) {
    // 두 수 중 작은 것을 기준으로 공통 약수가 나오는 순간 리턴한다.
    for (int i = min(a, b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}

// 유클리드 호제법으로 연산, a < b 보장되어야 함.
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;

    // 최대공약수 & 최소공배수 구하기
//    int g = gcdLoop(a, b);
    int g = gcd(a, b);
    int l = (a * b) / g;

    cout << g << '\n' << l;
    return 0;
}
