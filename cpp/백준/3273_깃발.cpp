#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
bool isExist(int value, int s, int e) {
    int mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (a[mid] == value)
            return true;
        if (a[mid] < value) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return false;
}
/*
 * [두 수의 합](https://www.acmicpc.net/problem/3273)
 * a[i] + a[j] = x이고 (1 ≤ i < j ≤ n)인 쌍을 찾는다.
 * 나는 입력받아 정렬한 뒤 (O(NlgN)) 각 N개의 원소에 대해 이분 탐색으로 확인했다. (O(N * lgN))
 *
 * 하지만 더 빠른 해는 다음과 같다. [#](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x03/solutions/3273.cpp)
 * x-a[i]가 존재하는지 확인하여 ans을 갱신하고 a[i] 값이 존재한다고 bool 배열에 1을 기록함.
 * 128MB
 * 공간 복잡도 계산: 1e5개의 int 배열 -> 4B*1e5 -> 400KB, 2e6 bool ->1B*2e6 -> 2MB 충분!
 */
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += isExist(x - a[i], i + 1, n -1);
    } cout << ans;
}