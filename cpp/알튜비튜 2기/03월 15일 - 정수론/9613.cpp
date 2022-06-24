#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) { // a > b 만족해야함.
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long gcdSum(int n, vector<int> &v) { // 범위 주의
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += gcd(max(v[i], v[j]), min(v[i], v[j])); // 센스
        }
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << gcdSum(n, arr) << '\n';
    }
}
