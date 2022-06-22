#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 모든 경우의 수를 계산할 때 10!의 이하의 경우 수가 존재. -> 완전 탐색 가능
int max_v = -1e9, min_v = 1e9;
int add, sub, mul, divi;
vector<int> seq, operation;

void dfs(int value, int idx, int n) {
    if (idx == n) {
        max_v = max(value, max_v);
        min_v = min(value, min_v);
        return;
    }

    if (add > 0) {
        add--;
        dfs(value + seq[idx], idx + 1, n);
        add++;
    }
    if (sub > 0) {
        sub--;
        dfs(value - seq[idx], idx + 1, n);
        sub++;
    }
    if (mul > 0) {
        mul--;
        dfs(value * seq[idx], idx + 1, n);
        mul++;
    }
    if (divi > 0) {
        divi--;
        dfs(value / seq[idx], idx + 1, n);
        divi++;
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        seq.push_back(input);
    }
    cin >> add >> sub >> mul >> divi;

    dfs(seq[0], 1, n);

    cout << max_v << "\n" << min_v << "\n";;
    return 0;
}
