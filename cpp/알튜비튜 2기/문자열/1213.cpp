#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
/*
 * 팰린드롬 만들기 [#](https://www.acmicpc.net/problem/1213)
 *
 * 틀린 이유: 홀수 개인 문자의 개수가 1을 초과할 때 시작 부분에 홀수 개인 문자를 추가해야한다.
 */
bool isPs(map<char, int> al_cnt) {
    int odd_cnt = 0;
    for (auto [al, cnt]: al_cnt) {
        if (cnt % 2 != 0) { // 홀수
                odd_cnt++;
        }
        if (2 <= odd_cnt) {
            return false;
        }
    }
    return true;
}
string makePalin(map<char, int> al_cnt) {
    string st = "", mid = "";
    for (auto [al, cnt]: al_cnt) {
        if (cnt % 2 != 0) { // 홀수
            mid.append(1, al);
        }
        for (size_t i = 0; i < cnt / 2; i++) {
            st.append(1, al);
        }
    }
//    cout << "st에 저장된 값은 " << st << '\n';
//    cout << "mid에 저장된 값은 " << mid << '\n';
    string end = st;
    reverse(end.begin(), end.end());
    st.append(mid);
    st.append(end);
    return st;
}

int main() {
    string name;
    cin >> name;

    map<char, int> al_cnt;
    for (char i: name) {
        al_cnt[i]++;
    }
    if (!isPs(al_cnt)) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }
    cout << makePalin(al_cnt) << '\n';
}