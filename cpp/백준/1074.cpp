#include <iostream>
using namespace std;

int z(int r, int c, int size) { // 0, 0, 3
    if (size == 0) {
        return 0;
    }
    int sq = 1 << (size-1); // sq = pow(2, size-1)
    if (sq <= r && sq <= c) {
        return 3 * sq*sq + z(r + sq, c + sq, size-1);;
    } else if (sq <= r) {
        return 2*sq*sq + z(r + sq, c, size-1);
    } else if (sq <= c) {
        return sq*sq + z(r, c + sq, size-1);
    } else {
        return z(r, c, size-1);
    }
}
int main() {
    int n, r, c;
    cin >> n >> r >> c;
    cout << z(r, c, n);
}
