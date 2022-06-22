#include <iostream>

using namespace std;

// 곱하기 또는 더하기
// 입력 예시
// 0 1 2 3 0 1 4
// 0 1 3 9 9 10 40
int main() {
    freopen("../input.txt", "r", stdin);
    string str;
    int res = 0;
    cin >> str;
    for (char i : str) {
        int cur = i - '0';
        if (res == 0 || cur == 0 || res == 1 || cur == 1) {
            res += cur;
        } else {
            res *= cur;
        }
    }
    cout << res << "\n";
    return 0;
}