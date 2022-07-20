#include <iostream>

using namespace std;
typedef long long ll;

void printTime(ll time) {
    cout << ((time / 3600) ? (time / 3600) : 0) << ' '
         << (((time % 3600) / 60) ? ((time % 3600) / 60) : 0)  << ' '
         << ((time % 60) ? (time % 60) : 0) << '\n';
}

/*
 * 창용이의 시계
 *
 * underflow 처리할 때 0보다 작을 때 1번만 더하는 것이 아니라 양수가 될 때까지 여러 번 더해주어야 함.
 */

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int h, m, s, tc, cmd, in;
    cin >> h >> m >> s;
    ll time = h * 3600 + m * 60 + s;
    cin >> tc;
    while (tc--) {
        while (time < 0) {
            time += 24 * 3600;
        }
        if (24 * 3600 <= time) {
            time %= 24 * 3600;
        }
        cin >> cmd;
        if (cmd == 3) {
            printTime(time);

            continue;
        }
        cin >> in;
        if (cmd == 1) {
            time += in;
        } else {
            time -= in;
        }
    }
}

/*
0 1 0
8
1 10000000
3
2 19999999
3
2 1
3
1 2
3
 */