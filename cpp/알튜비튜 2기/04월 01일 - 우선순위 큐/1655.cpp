#include <iostream>
#include <queue>

using namespace std;
/*
 * 가운데를 말해요 [#](https://www.acmicpc.net/problem/1655)
 * 중간 값을 기준으로 작은 값들은 최대 힙에 저장하고, 큰 값들은 최소 힙에 저장하여 풀이
 */
int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, a, mid;
    cin >> n;
    priority_queue<int> smaller; // 큰 수가 나오는
    priority_queue<int, vector<int>, greater<> > bigger; // 작은 수가 나오는
    cin >> mid;
    cout << mid << '\n';
    for (int i = 2; i <= n; i++) {
        cin >> a;
        if (a < mid) {
            smaller.push(a);
            if (i % 2 == 0) {
                bigger.push(mid);
                mid = smaller.top(); smaller.pop();
            }
        } else {
            bigger.push(a);
            if (i % 2 == 1) {
                smaller.push(mid);
                mid = bigger.top(); bigger.pop();
            }
        } cout << mid << '\n';
    }
}