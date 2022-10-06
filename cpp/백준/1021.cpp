#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, m, t, cnt, ans = 0;
    cin >> n >> m;
    cnt = n;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (m--) {
        cin >> t;
        int rot = 0;
        while (q.front() != t) {
            q.push(q.front());
            q.pop();
            rot++;
        }
        q.pop();
        ans += min(rot, cnt - rot);
        cnt--;
    }
    cout << ans;
}
/*
 * [회전하는 큐](https://www.acmicpc.net/problem/1021)
 *
 * 나는 큐를 사용해 항상 한 방향으로만 돌린 뒤
 * 21번째 줄과 같이 회전 횟수와 전체 크기-회전 횟수 중 작은 값을 담았다.
 * 하지만 덱을 활용해서 항상 적은 방향으로 돌리도록 구현할 수 있다.
 * find라는 함수가 주요 열쇠이다. algorithm 헤더에 있다.
 * 아래 코드는 샘플 코드이다.
 */
#include <algorithm>
void solution() {
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);
    int ans = 0;
    while (m--) {
        int t;
        cin >> t;
        int idx = find(dq.begin(), dq.end(), t) - dq.begin(); // idx: t가 있는 위치
        while (dq.front() != t) {
            if (idx < dq.size() - idx) { // 왼쪽으로 회전해서 더 빨리 찾을 수 있음.
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else { // 오른쪽으로 회전해서 더 빨리 찾을 수 있음.
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }
    cout << ans;
}