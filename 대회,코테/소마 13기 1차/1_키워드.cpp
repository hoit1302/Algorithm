#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
    int n, t;
    cin >> n;
    vector<string> keywords;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        keywords.push_back(tmp);
    }
//    keywords.
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> tmp;
        int cnt = 0;

        // algorithm
        for (string keyword : keywords) {
            bool flag = true;
            for (unsigned int j = 0; j < tmp.size(); j++) {
                if (tmp[j] != keyword[j])
                    flag = false;
            }
            if (flag)
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
