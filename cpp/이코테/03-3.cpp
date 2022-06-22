#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, a, res;
    cin >> N >> M;
    vector<int> minV;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < M; j++) {
            cin >> a;
            v.push_back(a);
        }
        minV.push_back(*min_element(v.begin(), v.end()));
    }
    for (int i = 0; i < minV.size(); i++)
        cout << minV[i] << " ";
    cout << "\n";
    res = *max_element(minV.begin(), minV.end());
    cout << res << "\n";
    return 0;
}
