#include <iostream>

using namespace std;

string getRes(int x, int len) {
    // 1. 컴파일 에러
    if (len != 1 && len % 2) {
        return "ERROR";
    }

    // 2. 무한으로 출력하는 경우
    if (len == 0 && 0 < x || len == 1 && x < 0) {
        return "INFINITE";
    }

    // 3. 0번 출력하는 경우
    if (x <= 0 || len == 1 && 0 < x) {
        return "0";
    }
    // 4. 1개 이상 셀 수 있는 횟수 출력
    len /= 2;
    return to_string((x + len - 1) / len - 1);
}
int main() {
    int x, n;
    cin >> x >> n;
    cout << getRes(x, n);
}