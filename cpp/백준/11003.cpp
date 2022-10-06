#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> ci;
int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, l, t;
    cin >> n >> l;
    priority_queue<ci, vector<ci>, greater<> > pq;
    for (int i = 0; i < n; i++) {
        cin >> t;
        pq.push({t, i});
        while (pq.top().second <= i - l) {
            pq.pop();
        }
        cout << pq.top().first << ' ';
    }
}
/*
 * [최솟값 찾기](https://www.acmicpc.net/problem/11003)
 * 나는 우선순위 큐를 활용했다.
 * 새로운 값과 idx 번호를 같이 넣어서
 * 가장 작은 값이 범위 외의 오래된 값이면 유효 범위 내의 값이 나타날 때까지 pop 해주었다.
 * 샘플 코드에서는 덱을 활용해 deque안의 숫자들은 오름차순 상태를 유지하고
 * 항상 맨 앞(front)의 값은 구간내 가장 작은 값을 가지도록 구현했다.
 * 덱을 활용하여 다시 풀어보면 좋겠다.
 */

void solution() {
    int n, l, num;
    deque<ci> dq;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        // 새로운 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막에 위치함.
        while (!dq.empty() && dq.back().second >= num) {
            dq.pop_back();
        }
        // 새로운 숫자는 항상 삽입.
        dq.push_back({i, num});
        // 주어진 구간을 벗어나는 outdate된 숫자들 제거. 한 칸씩 이동하므로 한 칸만 지워주면 됨.
        if (dq.front().first <= i - l) {
            dq.pop_front();
        }
        cout << dq.front().second << " ";
    }
}