#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, c; // nPr
    cin >> n >> c;
    vector<int> comb;
    for (int i = 1; i <= n; i++) {
        comb.push_back(i);
    }
    do {
        for (int i = 0; i < c; i++) {
            if (comb[i]) {
                cout << comb[i] << ' ';
            }
        } cout << '\n';
        reverse(comb.begin() + c, comb.end());
    } while (next_permutation(comb.begin(), comb.end())); // 1 0 0
}

/*
 * 4P2일 때
 * 1234 -> 12 출력됨
 * 1243 -> 중복되므로 위에서 12를 출력한 뒤에 c개 이후의 나머지 값들로만 reverse 시켜서 건너뛰도록 함.
 */