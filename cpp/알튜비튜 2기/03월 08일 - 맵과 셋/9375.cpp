#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string name, kind;
        unordered_map<string, int> map;

        cin >> n;
        while (n--) {
            cin >> name >> kind;
            map[kind]++;
        }

        int res = 1;
        for (auto &i: map) {
            res *= (i.second + 1);
        }
        cout << res - 1 << '\n';
    }
    return 0;
}
