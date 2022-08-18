#include <string>
#include <vector>
#include <stack>
using namespace std;
/*
 * 괄호 변환 [#](https://school.programmers.co.kr/learn/courses/30/lessons/60058)
 * 풀이 시간: 19분
 */

int findBalPos(string s) { // 균형잡힌 마지막 위치 반환
    int open = 0, close = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') open++;
        else close++;
        if (open == close) {
            return i;
        }
    }
    return s.size() - 1;
}
bool isValid(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(0);
        } else if (st.empty()) {
            return false;
        } else {
            st.pop();
        }
    }
    if (!st.empty()) return false;
    return true;
}
string reverse(string p) {
    string ans;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            ans.append(1, ')');
        } else {
            ans.append(1, '(');
        }
    } return ans;
}
string solution(string p) {
    if (p.empty()) return p;
    int bal_last = findBalPos(p);
    string u = p.substr(0, bal_last + 1), v = p.substr(bal_last + 1);
    if (isValid(u)) {
        return u + solution(v);
    }
    string tmp = "(" + solution(v) + ")";
    string a = u.substr(1, u.length() - 2);

    return tmp + reverse(a);
}