#include <string>
#include <vector>
#include <iostream>
using namespace std;

string step1(string s) {
    string a;
    for (char ch: s) {
        if ('A' <= ch && ch <= 'Z') {
            a.append(1, ch + ('a' - 'A'));
        } else {
            a.append(1, ch);
        }
    }
    return a;
}
string step2(string s) {
    string a;
    for (char ch: s) {
        if (isalnum(ch) || ch == '-' || ch == '_' || ch == '.') {
            a.append(1, ch);
        }
    }
    return a;
}
string step3(string s) {
    string a;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '.' || i == 0 || s[i] == '.' && 0 < i && s[i - 1] != '.') {
            a.append(1, s[i]);
        }
    }
    return a;
}
string step4(string s) {
    if (s.size() == 0) return s;
    if (s[0] == '.') {
        s = s.substr(1);
    }
    if (s[s.size() - 1] == '.') {
        s = s.substr(0, s.size() - 1);
    } return s;
}
string step5(string s) {
    if (s.empty()) {
        return "a";
    } return s;
}
string step6(string s) {
    if (16 <= s.size())
        s = s.substr(0, 15);
    return step4(s);
}
string step7(string s) {
    if (s.size() <= 2) {
        char last = s[s.size() - 1];
        for (int i = s.size(); i < 3; i++) { // 2
            s.append(1, last);
        }
    } return s;
}
/*
 * [신규 아이디 추천](https://school.programmers.co.kr/learn/courses/30/lessons/72410)
 * 풀이 시간 30분
 * step 3: 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
 * -> 첫번째 .은 추가하고 이후 연속해서 . 이 나오면 무시하도록 로직 작성함.
 * step 4: new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
 * -> s = s.substr(시작점, 원하는 길이) 활용하기
 */
string solution(string new_id) {
    return step7(step6(step5(step4(step3(step2(step1(new_id)))))));
}