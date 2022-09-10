#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(int n, int m, vector<int> &snacks) {
    int ans = 0; // 나누어 줄 수 없는 답으로 초기화
    int s = 1, e = snacks[0];
    while (s <= e) {
        int mid = (s + e) / 2, eat_num = 0;
        for (int snack : snacks) {
            eat_num += snack / mid;
            if (eat_num >= m) {
                break;
            }
        }

        if (eat_num >= m) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> m >> n;
    vector<int> snack(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> snack[i];
    }
    sort(snack.begin(), snack.end(), greater<>());
    cout << binary_search(n, m, snack) << '\n';
}
