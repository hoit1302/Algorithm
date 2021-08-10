#include <math.h>
#include <iostream>
using namespace std;

int N, r, c;

int solve() {
    int result = 0, t_r = 0, t_c = 0;
    while (N > 0) {
        int std = pow(2, N) / 2;
        int plus = pow(2, (N - 1) * 2);
        if (r < t_r + std && c < t_c + std)
            result += 0;
        else if (r < t_r + std && t_c + std <= c) {
            result += 1 * plus;
            t_c += std;
        } else if (t_r + std <= r && c < t_c + std) {
            result += 2 * plus;
            t_r += std;
        } else {
            result += 3 * plus;
            t_r += std;
            t_c += std;
        }
        N--;
    }
    return result;
}

int main() {
    cin >> N >> r >> c;
    cout << solve() << "\n";
    return 0;
}