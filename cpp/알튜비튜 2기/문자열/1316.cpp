#include <iostream>
#include <vector>

using namespace std;
/*
 * 그룹 단어 체커 [#](https://www.acmicpc.net/problem/1316)
 * 풀이시간: 8분
 * 핵 쉬움. 알파벳은 26개, 방문 처리하기
 */
bool isGroupWord(string s) {
    bool alphabet[26];
    fill_n(alphabet, 26, false);
    alphabet[s[0] - 'a'] = true;
    char prev = s[0];
    for (size_t i = 1; i < s.size(); i++) {
        if (prev == s[i]) {
            continue;
        }
        // 다를 때
        if (alphabet[s[i] - 'a']) {
            return false;
        }
        // 이전과 다르고 처음 방문
        alphabet[s[i] - 'a'] = true;
        prev = s[i];
    }
    return true;
}
int main() {
    int n, ans = 0;
    string str;
    cin >> n;
    while (n--) {
        cin >> str;
        if (isGroupWord(str)) {
            ans++;
        }
    }
    cout << ans;
}