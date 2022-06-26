#include <iostream>

using namespace std;

typedef pair<int, int> ci;
const int MAX = 1e6;

ci calFloor1(int r, int b) {
    int l, w, total = r + b;
    for (int i = 1; i < MAX; i++) {
        if (b % i != 0) {
            continue;
        }
        // 나누어 떨어지면 빨간색 타일로 덮었을 때도 만족하는지 확인
        int tmp_l = i + 2, tmp_w = b / i + 2;
        if (total == tmp_l * tmp_w) {
            l = tmp_l;
            w = tmp_w;
            break;
        }
    }
    return {max(l, w), min(l, w)};
}

ci calFloor2(int r, int b) {
    int l, w;
    r = (r - 4) / 2;
    for (int i = 1; i < r; i++) {
        if (b == i * (r - i)) {
            l = i + 2, w = r - i + 2;
        }
    }
    return {max(l, w), min(l, w)};
}

int main() {
    int r, b;
    cin >> r >> b;

    ci res = calFloor1(r, b);
    ci res2 = calFloor2(r, b);

    cout << res.first << ' ' << res.second << '\n';
    cout << res2.first << ' ' << res2.second << '\n';
}
