#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, 0);
    v[0] = v[1] = 1;
    int seq = 1, res = 0;
    while (seq <= k) {

        int prime_num;
        for (int i = 1; i <= n; i++) {
            if (v[i] == 0) {
                prime_num = i;
                break;
            }
        }

        for (int i = 1; i * prime_num <= n; i++) {
            if (seq > k)
                break;
            if (!v[i * prime_num]) {
                v[i * prime_num] = seq++;
                res = i * prime_num;
            }
        }
    }

    cout << res << '\n';
    return 0;
}