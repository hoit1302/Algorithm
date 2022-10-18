#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, c; // nCr, 값 입력받음.
    cin >> n >> c;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> comb(n, 0);
    for (int i = 0; i < c; i++) {
        comb[i] = 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            if (comb[i]) {
                cout << v[i] << ' ';
            }
        } cout << '\n';
    } while (prev_permutation(comb.begin(), comb.end())); // 1 1 1 0
}
