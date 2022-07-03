#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> e(n - 1, 0), city(n, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> e[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> city[i];
    }

    long long res = 0;
    int min_l = city[0];
    for (int i = 0; i < n - 1; i++) {
        if (city[i] < min_l) {
            min_l = city[i];
        }
        res += (min_l * (long) e[i]);
    }
    cout << res << '\n';
}