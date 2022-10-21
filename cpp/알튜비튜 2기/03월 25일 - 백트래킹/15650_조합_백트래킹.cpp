#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

/*
 * nCr 조합
 */
void go(int depth, int prev, string seq) {
    if (depth == m) {
        cout << seq << '\n';
        return;
    }
    for (int i = prev + 1; i <= n; i++) {
        go(depth + 1, i, seq + to_string(i) + " ");
    }
}

int main() {
    cin >> n >> m;
    go(0, 0, "");
}