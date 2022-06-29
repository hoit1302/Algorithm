#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, in;
    priority_queue<int, vector<int>, greater<> > pq;
    cin >> n;

    for (int i = 0; i < n * n; i++) {
        cin >> in;
        pq.push(in);
        if (pq.size() == n + 1) {
            pq.pop();
        }
    }
    cout << pq.top() << '\n';
}