#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ci;

ci findTwoLiq(int n, vector<int> & l_s) {
    int min_v = 2e9 + 1;
    ci ans;
    int l = 0, r = n - 1;
    while (l < r) {
        int dif = abs(l_s[l] + l_s[r]);
        if (dif < min_v) {
            min_v = dif;
            ans = {l_s[l], l_s[r]};
        }
        if (l_s[l] + l_s[r] < 0) {
            l++;
        } else if (l_s[l] + l_s[r] == 0) {
            break;
        } else {
            r--;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> liq_s(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liq_s[i];
    } sort(liq_s.begin(), liq_s.end());
    ci ans = findTwoLiq(n, liq_s);
    cout << ans.first << ' ' << ans.second << '\n';
}