#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/*
 * 문제 이름: 괄호 변환
 * https://school.programmers.co.kr/learn/courses/30/lessons/60058
 * 풀이 시간 50분 이내
 * 틑린 이유: 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 에서 뒤집는 거에만 집중해서 냅다 reverse 해버렸음.
 *
 * reverse는 algorithm 헤더에 있고 reverse(str.begin(), str.end());
 * str.substr(1, u.size() - 2); // 시작, 길이
 * str.append(tmp);
 */

// 균형잡힌 괄호 문자열 u 구하기 correct!
int findPos(string in) {
    int open = 0;
    for (size_t i = 0; i < in.size(); i++) {
        if (in[i] == '(') {
            open++;
        } else {
            open--;
        }
        if (open == 0) {
            return i;
        }
    }
    return (int) in.size() - 1;
}

// 올바른 괄호 확인 correct!
bool isValid(string in) {
    stack<char> st;
    for (char a : in) {
        if (a == '(') {
            st.push('(');
        } else {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    if (!st.empty()) {
        return false;
    }
    return true;
}

string changeValidString(string in) {
    if (in == "") {
        return "";
    }
    if (isValid(in)) {
        return in;
    }
    int pos = findPos(in);
    string u = in.substr(0, pos + 1), v = in.substr(pos + 1);
    if (isValid(u)) { // 3.
        return u.append(changeValidString(v)); // 3-1.
    } else { // 4.
        string make = "("; // 4-1.
        make.append(changeValidString(v)); // 4-2.
        make.append(")"); // 4-3.
        u = u.substr(1, u.size() - 2); // 4-4.
        for (char ch : u) { // 4-4.
            if (ch == '(')
                make.append(")");
            else
                make.append("(");
        }
        return make;
    }
}

string solution(string p) {
    return changeValidString(p);
}