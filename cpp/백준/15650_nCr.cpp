#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, c; // nCr, n개의 0과 c개의 1이 있는 배열을 순열로 돌림. 그리고 1인 idx만 취함
    cin >> n >> c;
    vector<int> comb(n, 0);
    for (int i = 0; i < c; i++) {
        comb[i] = 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            if (comb[i]) {
                cout << i+1 << ' ';
            }
        } cout << '\n';
    } while (prev_permutation(comb.begin(), comb.end())); // 1 0 0
}
/*
 * nCr, 크기 n의 배열에서 c개의 1이 있고 나머지는 0인 배열을 순열로 돌림. 그리고 1인 idx만 취함
 * 첫 시작을 1 1 1 0 0 (5C3)로 했다면 이게 마지막 수열이니 prev로 돌려줌.
 */