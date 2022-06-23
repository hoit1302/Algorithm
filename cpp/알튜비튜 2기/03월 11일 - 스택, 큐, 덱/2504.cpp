#include <iostream>
#include <stack>
#include <map>

using namespace std;

map<char, char> op;
map<char, int> num;

int calBracket(string bracket) {
    op[')'] = '(', op[']'] = '[';
    num['('] = 2, num['['] = 3;

    stack<char> st;
    int ans = 0, tmp = 1;
    for (int i = 0; i < bracket.size(); i++) {
        char ch = bracket[i];
        if (ch == '(' or ch == '[') {
            st.push(ch);
            tmp *= num[ch];
        } else if (ch == ')' or ch == ']') {
            if (st.empty() || st.top() != op[ch]) {
                return 0;
            }
            if (bracket[i - 1] == op[ch]) {
                ans += tmp;
            }
            tmp /= num[op[ch]];
            st.pop();
        }
        // cout << ch << ' ' << tmp << ' ' << ans << '\n';
    }
    if (!st.empty()) {
        return 0;
    }
    return ans;
}

int main() {
    string bracket;
    cin >> bracket;
    cout << calBracket(bracket) << '\n';
}

