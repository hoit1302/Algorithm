#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

vector<int> tips;

ll calTip(int n) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll tip = tips[i] - i;
        if (tip <= 0)
            return res; // break; 로 끊어도 ok
        res += tip;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    tips.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tips[i];
    }
    sort(tips.begin(), tips.end(), greater<>());
    cout << calTip(n) << '\n';
    return 0;
}
