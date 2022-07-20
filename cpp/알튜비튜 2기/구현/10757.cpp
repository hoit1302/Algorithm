#include <iostream>
#include <algorithm>
using namespace std;

string plusBig(string a, string b) {
    // reverse 시킨다.
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // 올림과 첫자리를 더해서 추가한다.
    string ans = "";
    int carry = 0;
    // 처리할 숫자 또는 올림이 하나라도 있다면 계산한다.
    while (!a.empty() || !b.empty() || carry == 1) {
        // cout << a << " + " << b << " + " << carry << '\n';
        int tmp = 0;
        if (!a.empty()) {
            tmp += a[0] - '0';
        }
        if (!b.empty()) {
            tmp += b[0] - '0';
        }
        tmp += carry;
        // 올림이 있으면 저장해둔다
        if (10 <= tmp) {
            carry = 1;
        } else {
            carry = 0;
        }
        ans.append(to_string(tmp % 10));
        // cout << ans << '\n';

        // 맨 앞자리를 지운다. == 자릿수 이동
        if (a.size() <= 1) {
            a = "";
        } else {
            a = a.substr(1);
        }
        if (b.size() <= 1) {
            b = "";
        } else {
            b = b.substr(1);
        }
    }


    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << plusBig(a, b);
}