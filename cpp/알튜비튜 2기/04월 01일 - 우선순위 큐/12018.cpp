#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> req(n, 0);
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        vector<int> v(p, 0);
        for (int j = 0; j < p; j++) {
            cin >> v[j];
        }
        if (p < l) {
            req[i] = 1;
            continue;
        }
        sort(v.begin(), v.end());
        if (p == l) {
            req[i] = v[0];
        } else if (p > l) {
            req[i] = v[p - l];
        }
    }

    sort(req.begin(), req.end());
    int total = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (total + req[i] > m) {
            break;
        }
        total += req[i];
        cnt++;
    }
    cout << cnt << '\n';
}