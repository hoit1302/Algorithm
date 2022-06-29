#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, cmd, present;
    priority_queue<int> pq;
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == 0) {
            if (pq.empty()) {
                cout << "-1\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
            continue;
        }

        // 0이 아닐 때
        while (cmd--) {
            cin >> present;
            pq.push(present);
        }
    }
}