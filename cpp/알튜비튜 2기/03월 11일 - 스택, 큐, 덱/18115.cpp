#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> dq;

void card_top(int num) {
    dq.push_front(num);
}

void card_sec_top(int sec) {
    int front = dq.front();
    dq.pop_front();
    dq.push_front(sec);
    dq.push_front(front);
}

void card_bottom(int num) {
    dq.push_back(num);
}

int main() {
    int n;
    cin >> n;
    vector<int> cal(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cal[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        int num = n - i;
        if (cal[i] == 1) {
            card_top(num);
        } else if (cal[i] == 2) {
            card_sec_top(num);
        } else if (cal[i] == 3) {
            card_bottom(num);
        }
    }

    for (int i: dq)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
