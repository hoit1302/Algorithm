#include <iostream>
#include <queue>

using namespace std;
typedef priority_queue<long, vector<long>, greater<>> min_heap;

long combineFile(min_heap &pq) {
    long total = 0, f, s;
    while (pq.size() >= 2) {
        f = pq.top();
        pq.pop();
        s = pq.top();
        pq.pop();
        total += (f + s);
        pq.push(f + s);
    }
    return total;
}
/*
 * 파일 합치기 3 [#](https://www.acmicpc.net/problem/13975)
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int k, in;
        cin >> k;
        min_heap pq;
        while (k--) {
            cin >> in;
            pq.push(in);
        }
        cout << combineFile(pq) << '\n';
    }
}