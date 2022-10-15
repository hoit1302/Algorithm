#include <iostream>
using namespace std;
// base condition 기저 조건: 1승을 계산할 수 있다.
// k승을 계산하면 2k승과 2k+1승도 O(1)에 계산할 수 있다.
// 수학적 지식: 만약 n^k mod c = tmp일 때, n^2k mod c = 2tmp mod c이다;
int pow(long long a, int b, int c) {
    if (b == 1) return a % c;
    long long tmp = pow(a, b/2, c);
    tmp = tmp * tmp % c;
    if (!(b % 2)) { // 나누어떨어짐
        return tmp;
    }
    return tmp * a % c;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
}
/*
 * 재귀함수는 절차지향적 사고 대신 귀납적인 사고로 이해하자
 * 절차지향적: (3, 5, 300)은 (3, 2, 300)을 호출하고 이는 (3, 1, 300)을 호출한다고 따라가기
 * 귀납적 사고:
 * 1번 도미노가 쓰러진다, k번 도미노가 쓰러지면 k+1번 도미노도 쓰러진다
 * 귀납적으로 -> 모든 도미노가 쓰러진다는 결론에 바로 도달
 * 재귀 함수의 조건: 기저 조건이 있어야하고 모든 입력은 기저조건으로 수렴해야한다
 */

