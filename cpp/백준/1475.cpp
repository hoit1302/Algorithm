#include <iostream>
using namespace std;
int cnt[10];
int main() {
    int a;
    cin >> a;
    while (a != 0) {
        cnt[a % 10]++;
        a /= 10;
    }
    cnt[6] += cnt[9];
    cnt[6] = (cnt[6] + 1) / 2; // 1~2 -> 1개; 3~4 -> 2개;
    int mx = 0;
    for (int i = 0; i <= 8; i++) {
        mx = max(mx, cnt[i]);
    }
    cout << mx;
}