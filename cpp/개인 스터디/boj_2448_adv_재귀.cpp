#include <iostream>

using namespace std;

char star[3072][6144];

void init(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            star[i][j] = ' ';
        }
    }
}

void pattern(int r, int c, int size) {
    if (size == 3) {
        star[r][c + 2] = '*';
        star[r + 1][c + 1] = star[r + 1][c + 3] ='*';
        for (int i = 0; i < 5; i++)
            star[r + 2][c + i] ='*';
        return;
    }

    pattern(r, c + size / 2, size / 2);
    pattern(r + size / 2, c, size / 2);
    pattern(r + size / 2, c + size, size / 2);
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << star[i][j];
        } cout << '\n';
    }
}

/*
 * 별 찍기 11 [#](https://www.acmicpc.net/problem/2448)
 * 개선한 풀이.
 * 빈 사각형에 별을 찍을 곳에만 찍어나가는 풀이
 * 훨씬 깔끔하고 쉽게 구현됨.
 */
int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    init(n);
    pattern(0, 0, n);
    print(n);
}
