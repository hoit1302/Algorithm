#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long w0, l0, T, D, l, A;
    cin >> w0 >> l0 >> T >> D >> l >> A;

    long w = w0 + D * (l - (l0 + A));
    if (w <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << w << ' ' << l0 << '\n';
    }

    long ch_w = w0, ch_l = l0;
    for (int i = 0; i < D; i++) {
        ch_w += l - (ch_l + A);
        if (abs(l - (ch_l + A)) > T) {
            ch_l += floor((double)(l - (ch_l + A)) / 2);
            // 이렇게도 구현할 수 있음.
            /*
            if (l - (ch_l + A) < 0) {
                ch_l += (l - (ch_l + A) - 1) / 2;
            } else {
                ch_l += (l - (ch_l + A)) / 2;
            }
             */
        }
    }

    string yoyo = "NO";
    if (l0 - ch_l > 0) {
        yoyo = "YOYO";
    }

    if (ch_w <= 0 || ch_l <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << ch_w << ' ' << ch_l << ' ' << yoyo << '\n';
    }
}