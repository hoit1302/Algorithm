#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;

bool cmp(const string &a, const string &b) {
    if (map[a] != map[b])
        return map[a] > map[b];
    if (a.length() != b.length())
        return a.length() > b.length();
    return a < b;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    string input;
    vector<string> v;
    cin >> n >> m;
    while (n--) {
        cin >> input;
        if (input.length() < m) {
            continue;
        }
        if (!map[input]) {
            v.push_back(input);
        }
        map[input]++;
    }

    sort(v.begin(), v.end(), cmp);
    for (string w : v) {
        cout << w << '\n';
    }
    return 0;
}
