#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string chToStr(vector<char> tmp) {
    string ans;
    for (char ch: tmp) {
        ans.append(1, ch);
    }
    return ans;
}

bool check(vector<char> tmp) {
    int cnt = 0; // 모음 개수
    string one = "aeiou";
    for (char ch: tmp) {
        for (int i = 0; i < 5; i++) {
            if (ch == one[i]) {
                cnt++;
            }
        }
    }
    if (1 <= cnt && 2 <= (int) tmp.size() - cnt) {
        return true;
    } return false;
}

int main() {
    // 1. 입력, 정렬
    int l, c;
    cin >> l >> c;
    vector<char> chs(c, ' ');
    for (int i = 0; i < c; i++) {
        cin >> chs[i];
    }
    sort(chs.begin(), chs.end());

    // 2. combination(l, c) 구하기
    vector<bool> com(c, false);
    for (int i = 0; i < l; i++) {
        com[i] = true;
    }

    vector<string> ans;
    do {
        vector<char> tmp;
        for (int i = 0; i < c; i++) {
            if (com[i]) {
                tmp.push_back(chs[i]);
            }
        }
        if (check(tmp)) {
            ans.push_back(chToStr(tmp));
        }
    } while (prev_permutation(com.begin(), com.end()));

    // 3. 출력
    for (string str: ans) {
        cout << str << '\n';
    }
}