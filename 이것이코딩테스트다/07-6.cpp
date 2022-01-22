#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[1000001];
vector<int> targets;

// p. 197: 부품 찾기
// 같은 문제이지만 계수 정렬 방식으로 풀이
int main() {
    freopen("../input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }

    for (int i = 0; i < m; i++) {
        if (arr[targets[i]] == 1) {
            cout << "yes" << ' ';
        } else {
            cout << "no" << ' ';
        }
    }
}