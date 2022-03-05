#include <iostream>

using namespace std;

// 메세지 복호값

int main() {
    int a, b;
    string str, res = "";
    cin >> a >> b >> str;
    for (unsigned int i = 0; i < str.size(); i++) {
        char ch = str[i];
        int ch_int = ch - 'a';
        bool flag = true;
        while (flag) {
            if ((ch_int - b) % a != 0) {
                ch_int = ch_int + 26;
            } else {
                char find = (((ch_int - b) / a)) + 'a';
                res += find;
//                cout << (ch_int - b) / a << " ";
                flag = false;
            }
        }
    }
    cout << res << "\n";
    return 0;
}
