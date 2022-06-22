#include <iostream>
#include <set>

using namespace std;

// substr O(N), 사용해 부분 문자열 구하기
int cntDiff1(string s) {
    set<string> set;
    for (int i = 0; i < s.length(); i++) { // i : 문자열 시작 인덱스
        for (int j = 1; j <= s.length() - i; j++) { //j :문자열 길이
            set.insert(s.substr(i, j));
        }
    }
    return set.size();
}

// += O(1), 직접 이어 붙여 부분 문자열 구하기
int cntDiff2(string s) {
    set<string> set;
    for (int i = 0; i < s.length(); i++) {
        string temp = "";
        for (int j = i; j < s.length(); j++) {
            temp += s[j]; // i-j 부분 문자열
            set.insert(temp); // 삽입
        }
    }
    return set.size();
}
int main() {
    string s;
    cin >> s;

    cout << cntDiff1(s);
    cout << cntDiff2(s);
}
