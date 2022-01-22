#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// p. 178: 위에서 아래로
int main() {
    freopen("../input.txt", "r", stdin);
    int N, a;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> a;
        v[i] = a;
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < N; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}
