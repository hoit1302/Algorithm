#include <iostream>
#include <vector>

using namespace std;

void flipPro(vector<string> &pro, int r, int c) {
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            pro[i][j] = (pro[i][j] - '0') ? '0' : '1';
        }
    }
}

bool isTrue(vector<string> &pro, vector<string> &ans, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pro[i][j] != ans[i][j]) {
                return false;
            }
        }
    }
    return true;
}

//void print(vector<string> &pro, int n, int m) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << pro[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> pro(n), ans(n);
    for (int i = 0; i < n; i++) {
        cin >> pro[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }

//    print(pro, n, m);

    int res = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (pro[i][j] != ans[i][j]) {
                res++;
                flipPro(pro, i, j);
            }
        }
    }

    if (isTrue(pro, ans, n, m)) {
        cout << res << '\n';
    } else {
        cout << "-1\n";
    }
}