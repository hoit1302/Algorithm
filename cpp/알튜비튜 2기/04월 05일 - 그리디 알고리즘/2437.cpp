#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6;

int immea(int n, vector<int> &w_s) {
    int not_visited = 1; // w_s[i] 무게의 추로 새롭게 측정해야하는 무게 중 가장 작은 값
    for (int i = 0; i < n; i++) { // 추 종류
        // cout << w_s[i] << '\n';
        if (not_visited - w_s[i] < 0) { // 가장 작은 값이 측정될 수 없음. 해당 값이 정답임.
            return not_visited;
        }
        not_visited += w_s[i]; // 다음 무게 추가 새롭게 측정해야하는 무게 중 가장 작은 값으로 갱신
    }
    return not_visited;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> weights(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    cout << immea(n, weights) << '\n';
}