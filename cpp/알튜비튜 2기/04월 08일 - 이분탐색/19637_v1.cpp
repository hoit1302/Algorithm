#include <iostream>
#include <map>

using namespace std;

/**
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음 -> 이분 탐색
 * 더 좋은 풀이
 */


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title;

    int n, m, power;
    string name;
    cin >> n >> m;
    while (n--) {
        cin >> name >> power;
        if (title[power].empty()) {
            title[power] = name;
        }
    }

    while (m--) {
        cin >> power;
        cout << title.lower_bound(power)->second << '\n'; // key 값과 같거나 큰 숫자
    }
}