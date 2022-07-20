#include <iostream>
#include <vector>
#include <deque>

using namespace std;
/*
 * 행운의 바퀴 [#](https://www.acmicpc.net/problem/2840)
 * 풀이시간: 26분
 * 틀린 이유: 바퀴에 같은 글자는 두 번 이상 등장하지 않는다.
 * 방문 확인하는 로직 추가하여 AC 받음.
 */
int main() {
    int n, k, t;
    char al;
    cin >> n >> k;
    deque<char> wheel(n, '?');
    vector<bool> visited(26, false);
    bool isPs = true;
    for (int i = 0; i < k; i++) {
        cin >> t >> al;
        // t번 돌리고
        for (int j = 0; j < t; j++) {
            wheel.push_front(wheel.back());
            wheel.pop_back();
        }
        // 1-이미 올바르게 할당된 경우, 2-비어있고 새로운 알파벳인 경우 할당, 3-그 외 불가능
        if (wheel[0] == al) {
            continue;
        } else if (wheel[0] == '?' && !visited[al - 'A']) {
            visited[al - 'A'] = true;
            wheel[0] = al;
        } else {
            isPs = false;
        }

        if (!isPs) {
            cout << "!\n";
            return 0;
        }
    }
    for (char e: wheel) {
        cout << e;
    }
    return 0;
}