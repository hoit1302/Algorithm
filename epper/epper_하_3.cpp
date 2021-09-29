#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    while(true) {
        cin >> s;
        if(s=="0")
            break;

        bool flag = true;
        int l = s.size();
        for (int i = 0; i < l / 2; i++) {
            if (s[i] != s[l-i-1]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}
