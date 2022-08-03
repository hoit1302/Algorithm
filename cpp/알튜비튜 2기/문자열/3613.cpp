#include <iostream>

using namespace std;

/*
 * JAVA vs C++ [#](https://www.acmicpc.net/problem/3613)
 * 1. 형식 판단 (올바른지도 판단)
 * error: _나 대문자로 시작할 때, _ 연속으로 나올 때, 대문자와 _가 모두 등장할 때, _로 끝날 때
 * 2-1. c++ -> java 변환: _를 없애고 바로 다음 문자를 대문자로
 * 2-2  c++ <- java 변환: 대문자를 소문자로 바꾸고 앞에 _ 삽입
 *
 * 문자열 다룰 때 엣지 케이스 (첫, 끝 경계 부분) 잘 보기
 */
string findType(string str) {
    if (str[0] == '_' || isupper(str[0]) || str[str.size() - 1] == '_') {
        return "Error!";
    }
    bool is_java = false, is_cpp = false;
    char prev = '.';
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            is_java = true;
        } else if (str[i] == '_') {
            is_cpp = true;
            if (prev == '_') {
                return "Error!";
            }
        }
        prev = str[i];
    }
    if (is_java && is_cpp) {
        return "Error!";
    }
    if (is_java) {
        return "JAVA";
    } return "C++";
}

string cppToJava(string str) {
    string ans;
    int upper = 'A' - 'a';
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '_') {
            ans.append(1, str[++i] + upper);
            continue;
        } ans.append(1, str[i]);
    }
    return ans;
}

string javaToCpp(string str) {
    string ans;
    int lower = 'A' - 'a';
    for (size_t i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            ans.append("_" + string(1, str[i] - lower));
            continue;
        } ans.append(1, str[i]);
    }
    return ans;
}
int main() {
    string in, res;
    cin >> in;
    res = findType(in);
    if (res == "Error!") {
        cout << res;
    } else if (res == "JAVA") {
        cout << javaToCpp(in);
    } else {
        cout << cppToJava(in);
    } return 0;
}