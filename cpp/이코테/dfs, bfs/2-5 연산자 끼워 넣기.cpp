#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 연산자 끼워넣기 [#](https://www.acmicpc.net/problem/14888)
 * 백트래킹, 순열 2가지 풀이가 가능하고 순열로 풀이했음.
 */
using namespace std;
const int INF = 1e9;
int main() {
    int n, a;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    vector<int> op;
    for (int i = 0; i < 4; i++) {
        cin >> a;
        while (a--) {
            op.push_back(i);
        }
    }
    int max_ = -INF, min_ = INF, cnt = (int) op.size();
    do {
        int tmp = num[0];
        for (int i = 0; i < cnt; i++) {
            if (op[i] == 0) {
                tmp += num[i + 1];
            } else if (op[i] == 1) {
                tmp -= num[i + 1];
            } else if (op[i] == 2) {
                tmp *= num[i + 1];
            } else {
                tmp /= num[i + 1];
            }
        }
        max_ = max(tmp, max_); min_ = min(tmp, min_);
    } while (next_permutation(op.begin(), op.end()));
    cout << max_ << '\n' << min_;
}