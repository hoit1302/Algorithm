#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'd' && str.substr(i, 3) == "dz=") {
            i += 2;
        }
        if (str[i] == 'c' || str[i] == 'd' || str[i] == 'l'
        || str[i] == 'n' || str[i] == 's' || str[i] == 'z') {
            string sp = str.substr(i, 2);
            if (sp == "c=" || sp == "c-" || sp == "d-" ||
                    sp == "lj" || sp == "nj" || sp == "s=" || sp == "z=") {
                i++;
            }
        }
        ans++;
    } cout << ans;
}