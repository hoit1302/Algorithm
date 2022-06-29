#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ci; // 값, 인덱스

int main() {
    char cmd;
    int tc, q, n, idx;
    cin >> tc;
    while (tc--) {
        cin >> q;
        idx = 0;
        vector<int> valid;
        priority_queue<ci> max_h;
        priority_queue<ci, vector<ci>, greater<>> min_h;
        while (q--) {
            cin >> cmd >> n;

            if (cmd == 'I') {
                max_h.push({n, idx});
                min_h.push({n, idx++});
                valid.push_back(true);
            } else if (cmd == 'D' && n == 1) {
                while (!max_h.empty() && !valid[max_h.top().second]) {
                    max_h.pop();
                }
                if (max_h.empty()) {
                    continue;
                }
                valid[max_h.top().second] = false;
                max_h.pop();
            } else if (cmd == 'D' && n == -1) {
                while (!min_h.empty() && !valid[min_h.top().second]) {
                    min_h.pop();
                }
                if (min_h.empty()) {
                    continue;
                }
                valid[min_h.top().second] = false;
                min_h.pop();
            }
        }

        while (!max_h.empty() && !valid[max_h.top().second]) {
            max_h.pop();
        }
        while (!min_h.empty() && !valid[min_h.top().second]) {
            min_h.pop();
        }
        if (max_h.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_h.top().first << ' ' << min_h.top().first << '\n';
        }
    }
}