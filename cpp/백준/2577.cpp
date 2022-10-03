#include <iostream>
using namespace std;
int cnt[10];
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a = a * b * c;
    while (a != 0) {
        cnt[a % 10]++;
        a /= 10;
    }
    for (int i = 0; i <= 9; i++) {
        cout << cnt[i] << '\n';
    }
}