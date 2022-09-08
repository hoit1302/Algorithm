#include <iostream>

using namespace std;

char star[3072][6144];

void triangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            star[i][j] = ' ';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + n; j++) {
            if (i + j < n - 1) {
                continue;
            }
            star[i][j] = '*';
        }
    }
}
void remove(int r, int c, int size) {
    if (size == 3) {
        star[r + 1][c + 2] = ' ';
        return;
    }
    r += size;
    int c_start = c + size - 1;
    for (int i = 1; i <= size / 2; i++) {
        for (int j = 0; j < i * 2 - 1; j++) {
            star[r - i][c_start + j] = ' ';
        } c_start--;
    }
}

void pattern(int r, int c, int size) {
    if (size == 1) return;
    remove(r, c, size);

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
 * 첫 풀이.
 * 삼각형을 먼저 그리고 지워나갈 부분을 지우는 방식으로 구현
 */
int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    triangle(n);
    pattern(0, 0, n);
    print(n);
}
