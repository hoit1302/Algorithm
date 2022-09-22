#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    int g;
    cin >> g;

    bool flag = false;
    int s = 1, e = 2; // 둘이 같으면 안됨.
    while (s < e) {
        // idx 접근 로직 시작
        ll diff = e * e - s * s;
        if (g == diff) { // 같으면
            cout << e++ << '\n';
            s++;
            flag = true;
            continue;
        }

        if (g < diff) { // 원하는 값보다 크면 줄이기
            s++;
        } else if (diff < g) { // 원하는 값보다 작으면 키우기
            e++;
        }
    }
    if (!flag) {
        cout << "-1\n";
    }
}