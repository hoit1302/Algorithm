#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, res;
    string s;
    cin >> n;
    res = n;
    while (n--) {
        cin >> s;
        vector<bool> visited(26, false);
        if (s.length() >= 1)
            visited[s[0] - 'a'] = true;
        for (int i = 1; i < s.length(); i++) {
            if (s[i-1] == s[i]) {
                continue;
            }
            if (visited[s[i] - 'a']) { // 이미 방문했다면
                res--;
                break;
            }
            // 처음 방문하면
            visited[s[i] - 'a'] = true;
        }
    }
    cout << res << '\n';
}

// 그룹인가? true/false를 리턴하는 함수를 만들어 true 값을 반환할 때 결과값에 1씩 더해주는 방식으로 구현
//// 직전 문자열과 비교할 때, 문자열 길이가 1 이상인지 판단하고 하는 게 아니라
//// 다르기만 하면 되기 때문에 다른 아무 문자로 cur = '.' 초기화해둠.