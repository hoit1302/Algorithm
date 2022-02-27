#include <iostream>
#include <vector>

using namespace std;

// 문제 조건 추가: 고정점이 있을 경우, 고정점이 하나임.
int binary_search_func(int s, int e, vector<int> seq) {
    bool flag = false;
    int mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (seq[mid] == mid) {
            flag = true;
            break;
        }
        if (s == e) {
            break;
        }
        if (seq[mid] < mid) { // 배열 값이 작음.
            s = mid + 1;
        } else if (seq[mid] > mid) { // 배열 값이 큼.
            e = mid - 1;
        }
    }
    return (!flag) ? -1 : mid;
}

int main() {
    freopen("../input.txt", "r", stdin);
    int n;
    vector<int> seq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        seq.push_back(tmp);
    }
    cout << binary_search_func(0, n - 1, seq) << "\n";
    return 0;
}
