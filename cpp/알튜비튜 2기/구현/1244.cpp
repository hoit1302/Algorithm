#include <iostream>
#include <vector>

using namespace std;

int flip(int a) {
    return (a == 0) ? 1 : 0;
}

vector<int> turnM(int num, int n, vector<int> &st) {
    for (int i = 1; num * i <= n; i++) {
        st[num * i] = flip(st[num * i]);
    }
    return st;
}

vector<int> turnW(int num, int n, vector<int> &st) {
    int s = num - 1, e = num + 1;
    while (0 < s && e <= n && st[s] == st[e]) {
        s--;
        e++;
    }
    s++;
    e--;
    // cout << s << ' ' << e << " ok\n";
    for (int i = s; i <= e; i++) {
        st[i] = flip(st[i]);
    }
    return st;
}

void printSwitch(int n, vector<int> &st) {// 출력
    for (int i = 1; i <= n; i++) {
        cout << st[i] << ' ';
        if (i != 0 && i % 20 == 0) {
            cout << '\n';
        }
    } cout << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, peo, s, num;
    cin >> n;
    vector<int> status(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> status[i];
    }
    cin >> peo;
    while (peo--) {
        cin >> s >> num;
        if (s == 1) {
            status = turnM(num, n, status);
        } else {
            status = turnW(num, n, status);
        }
    }
    printSwitch(n, status);
}