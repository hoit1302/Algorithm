#include <iostream>
#include <map>

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int res = 0;
    string s, e, q, time, name;
    map<string, bool> m;
    cin >> s >> e >> q;

    while (cin >> time >> name) {
        // cin은 if나 while 문 안에 들어가면
        // 예외적으로 operator에 의해 자동으로 bool로 바뀌어
        // 연산의 성공 여부에 대한 True/False 값을 반환한다.
        if (time <= s) {
            m[name] = true;
        } else if (e <= time && time <= q) {
            if (m[name]) {
                res++;
                m[name] = false;
            }
        }
    }

    cout << res << '\n';
    return 0;
}