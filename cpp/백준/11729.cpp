#include <iostream>
using namespace std;
void hanoi(int size, int s, int e) {
    if (size == 1) {
        cout << s << ' ' << e << '\n';
        return;
    }
    hanoi(size-1, s, 6-s-e);
    cout << s << ' ' << e << '\n';
    hanoi(size-1, 6-s-e, e);
}
int main() {
    cout.tie(0), ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    hanoi(n, 1, 3);
}
/*
 * 하노이 탑 이동 순서: https://www.acmicpc.net/problem/11729
 *
 * 원판이 1개일 때 원하는 곳으로 움직일 수 있다.
 * 원판이 k개일 때 옮길 수 있다면 k+1개일 때도 원판을 옮길 수 있다.
 * -> 재귀다!
 *
 * 1. 재귀 함수 정의: size개의 원판을 start에서 end로 옮겨라.
 * 2. 기저 조건: 원판이 1개일 때는 바로 start에서 end로 옮기고 끝내자
 * 3. 재귀식:
 * size-1개의 원판들은 start에서 mid로 모두 옮기고
 * size 크기의 원판을 start에서 end로 옮긴 다음에
 * mid에 있는 size-1개의 원판들을 end로 옮기면 된다.
 *
 * 테크닉 1. mid를 (1+2+3) - s - e로 구하는 것이고
 * 테크닉 2.
 * 초항 A1 = 1, An = 2*An-1 + 1의 일반항 An = 2^n - 1이므로
 * 개수는 (1 << n) - 1로 구할 수 있다.
 * 수식으로는 치환을 활용하여 일반항을 구할 수 있다.
 * Bn = An + 1 = 2*Bn-1
 */