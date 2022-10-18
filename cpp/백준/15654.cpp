#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, c; // nPr, 값 입력받음.
    cin >> n >> c;
    vector<int> comb(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> comb[i];
    }
    sort(comb.begin(), comb.end());
    do {
        for (int i = 0; i < c; i++) {
            cout << comb[i] << ' ';
        } cout << '\n';
        reverse(comb.begin() + c, comb.end());
    } while (next_permutation(comb.begin(), comb.end())); // 1 7 8 9
}
