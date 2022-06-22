#include <iostream>
#include <string>
using namespace std;
int main() {
    string s, ans = "";
    cin >> s;
    int tmp = 0;
    if (s[0] == '1') ans += "1";
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1])
            tmp++;
        else {
            ans += ('A' + tmp);
            tmp = 0;
        }
    }
    ans += ('A' + tmp);
    cout << ans << "\n";
    return 0;
}