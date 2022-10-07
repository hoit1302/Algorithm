#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, ans = 0;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        stack<char> st;
        for (auto ch: s) {
            if (st.empty() || !st.empty() && st.top() != ch) {
                st.push(ch);
            } else if (!st.empty() && st.top() == ch) {
                st.pop();
            }
        }
        if (st.empty()) ans++;
    }
    cout << ans;
}