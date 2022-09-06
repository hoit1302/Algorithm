#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch) {
    if (ch == '*' || ch == '/') { // 우선순위 가장 높음.
        return 1;
    }
    if (ch == '+' || ch == '-') {
        return 2;
    }
    return 3; // 우선순위 없음. -> 아이디어
}

/*
 * 후위 표기식 [#](https://www.acmicpc.net/problem/1918)
 * 진짜 어렵다...
 */
int main(){
    stack<char> op;
    string nota, post;
    cin >> nota;
    for (char ch: nota) {
        if (isalpha(ch)) { // 1. 문자이면
            post.append(1, ch);
            continue;
        }
        if (ch == '(') { // 2. 여는 괄호이면
            op.push(ch);
            continue;
        }
        if (ch == ')') { // 3. 닫는 괄호이면 여는 괄호 전까지의 연산자 처리
            while (!op.empty() && op.top() != '(') {
                post.append(1, op.top());
                op.pop();
            }
            op.pop(); // '(' 제거
            continue;
        }

        // 4. 연산자이면
        // 현재 연산자의 우선순위가 더 낮거나 같으면 스택에서 값을 꺼내 답에 추가
        // 스택의 top 연산자 우선순위가 가장 높아야 함!!!
        while (!op.empty() && priority(op.top()) <= priority(ch)) {
            post += op.top();
            op.pop();
        }
        op.push(ch);
    }
    while (!op.empty()) {
        post.append(1, op.top());
        op.pop();
    }
    cout << post;
}