#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, input;
        unordered_set<int> s;

        cin >> n;
        while (n--) {
            cin >> input;
            s.insert(input);
        }
        cin >> m;
        while (m--) {
            cin >> input;
            auto iter = s.find(input);
            if (iter == s.end())
                cout << "0\n";
            else
                cout << "1\n";
        }
    }
    return 0;
}

