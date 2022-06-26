#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> nums, op;
int max_ = -1e9, min_ = 1e9;
int rotate_cnt = 0;

void go(int depth, int cal) {
    rotate_cnt++;
    if (depth == n) {
        max_ = max(max_, cal);
        min_ = min(min_, cal);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] != 0) {
            op[i]--;
            if (i == 0)
                go(depth + 1, cal + nums[depth]);
            else if (i == 1)
                go(depth + 1, cal - nums[depth]);
            else if (i == 2)
                go(depth + 1, cal * nums[depth]);
            else if (i == 3)
                go(depth + 1, cal / nums[depth]);
            op[i]++;
        }
    }
}

int main() {
    cin >> n;
    nums.assign(n, 0);
    op.assign(4, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> op[0] >> op[1] >> op[2] >> op[3];
    go(1, nums[0]);
    cout << rotate_cnt << '\n';
    cout << max_ << '\n' << min_ << '\n';
}