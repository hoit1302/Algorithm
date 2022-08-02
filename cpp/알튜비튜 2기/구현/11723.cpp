#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 21;
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int M, x;
    string op;
    vector<bool> s(SIZE, false);
    cin >> M;
    while (M--) {
        cin >> op;
        if (op == "all") {
            s.assign(SIZE, true);
            continue;
        } else if (op == "empty") {
            s.assign(SIZE, false);
            continue;
        }

        cin >> x;
        if (op == "add") {
            s[x] = true;
        } else if (op == "check") {
            if (s[x])
                cout << "1\n";
            else
                cout << "0\n";
        } else if (op == "remove") {
            s[x] = false;
        } else if (op == "toggle") {
            if (s[x])
                s[x] = false;
            else
                s[x] = true;
        }
    }
}