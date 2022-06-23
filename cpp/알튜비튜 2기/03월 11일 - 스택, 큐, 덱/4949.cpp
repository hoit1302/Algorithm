#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool isBalanced(string &s) {
    stack<char> st;
    map<char, char> m;
    //괄호 짝 미리 저장
    m[']'] = '[';
    m[')'] = '(';

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '(': case '[':
                st.push(s[i]);
                break;
            case ')': case ']':
                if (st.empty() || st.top() != m[s[i]]) { //스택 비었거나 -> 먼저 확인해야함!, 종류 안맞음
                    return false;
                }
                st.pop();
                break;
        }
    }
    return st.empty(); //스택에 원소가 비어있어야 균형 o
}

int main() {
    string s;

    while (getline(cin, s)) {
        if (s == ".") {
            break;
        }
        if (isBalanced(s)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
