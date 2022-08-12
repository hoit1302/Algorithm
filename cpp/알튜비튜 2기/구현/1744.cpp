#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> getSumVector(vector<ll> ps) {
    vector<ll> sum;
    for (int i = 0; i < ps.size(); i += 2) {
        if (ps.size() <= i + 1) {
            sum.push_back(ps[i]);
            continue;
        }
        if (ps[i] == 1 || ps[i + 1] == 1) {
            sum.push_back(ps[i]);
            sum.push_back(ps[i + 1]);
            continue;
        }
        sum.push_back(ps[i] * ps[i + 1]);
    }
    return sum;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, a;
    cin >> n;
    vector<ll> ns, ps, zero;
    while (n--) {
        cin >> a;
        if (a < 0) {
            ns.push_back(a);
        } else if (0 < a) {
            ps.push_back(a);
        } else {
            zero.push_back(a);
        }
    }
    sort(ps.begin(), ps.end(), greater<>());
    sort(ns.begin(), ns.end());
    ps = getSumVector(ps);
    ns = getSumVector(ns);


    sort(ns.begin(), ns.end());
    for (int i = 0; i < zero.size(); i++) {
        if (i < ns.size() && ns[i] < 0) {
            ns[i] = 0;
        }
    }
    ll res = 0;
    for (ll b: ps) {
        res += b;
    }
    for (ll b: ns) {
        res += b;
    }
    cout << res;
}