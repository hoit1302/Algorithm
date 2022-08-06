#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
 * 회전초밥 [#](https://www.acmicpc.net/problem/2531)
 *
 * 투 포인터의 거리가 고정되어 있는 경우, 슬라이딩 윈도우
 * 이동할 때마다 map을 활용해 원소의 개수를 더하고 빼서 구현하여 주어진 시간 내에 풀이
 */

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    int max_kind = 0;
    map<int, int> m;
    m[c]++;
    for (int i = 0; i < k; i++) {
        m[sushi[i]]++;
    }
//    cout << 0 << ": " << m.size() << "개\n";
    max_kind = max(max_kind, (int) m.size());
    for (int i = 1; i < n; i++) {
        m[sushi[i - 1]]--;
        m[sushi[(i + k - 1) % n]]++;

        int kind = 0;
        for (auto [key, value] : m) {
            if (value) {
                kind++;
            }
        }
//        cout << i << ": " << kind << "개\n";
        max_kind = max(max_kind, kind);
    }
    cout << max_kind << '\n';
}