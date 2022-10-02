#include <iostream>

using namespace std;

char star[2187][2187];

void remove(int r, int c, int size) {
    r += size / 3; c += size / 3;
    for (int i = 0; i < size / 3; i++) {
        for (int j = 0; j < size / 3; j++) {
            star[r + i][c + j] = ' ';
        }
    }
}

void pattern(int r, int c, int size) {
    if (size == 1) return;
    remove(r, c, size);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            pattern(r + i * (size / 3), c + j * (size / 3), size / 3);
        }
    }
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << star[i][j];
        } cout << '\n';
    }
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        star[i][j] = '*';
    }
    pattern(0, 0, n);
    print(n);
}
