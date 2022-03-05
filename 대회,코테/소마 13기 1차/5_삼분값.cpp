#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 삼분값

int main() {
    int a, b, n, x, y, z;
    cin >> a >> b >> n;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);

    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        sort(v.begin(), v.end());
        cout << v[i] << " " << v[i * 2 + 1] << '\n';
    }
    return 0;
}
