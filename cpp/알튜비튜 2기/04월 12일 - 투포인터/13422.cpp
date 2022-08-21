#include <iostream>
#include <vector>

using namespace std;

/*
 * 도둑 [#](https://www.acmicpc.net/problem/13422)
 *
 * 첫번째 집과 마지막 집이 이웃한 형태 다루기
 * 슬라이딩 윈도우 문제인데 오랜만에 만나서 아이디어를 떠올리지 못함
 * 코너 케이스: 집 개수가 n이고 한 번에 훔쳐야하는 개수인 m이 n과 같을 때.
 * 이 때는 딱 1번만 확인하고 0 또는 1을 출력하면 됨.
 */
vector<int> houses;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc, n, m, k, ans;
    cin >> tc;
    while (tc--) {
        ans = 0;
        cin >> n >> m >> k;
        houses.assign(n, 0);

        long long tmp_acc = 0;
        for (int i = 0; i < n; i++) {
            cin >> houses[i];
            if (i < m) {
                tmp_acc += houses[i];
            }
        }
        if (n == m) {
            if (tmp_acc < k) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
            continue;
        }

        for (int i = 0; i < n; i++) {
            // cout << i << ' ' << tmp_acc << '\n';
            if (tmp_acc < k) {
                ans++;
            }
            tmp_acc = tmp_acc + houses[(i + m) % n] - houses[i];
        }
        cout << ans << '\n';
    }
}