#include <iostream>
using namespace std;
char arr[64][64];
bool isSame(int r, int c, int size) {
    char pre = arr[r][c];
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (pre != arr[i][j]) return false;
            pre = arr[i][j];
        }
    }
    return true;
}
// 재귀 함수 정의: r,c에서 size 만큼의 사각형을 압축해라
void compress(int r, int c, int size) {
    // 기저 조건: 더이상 나눌 수 없거나 압축 가능하면 압축하기
    if (size == 1 || isSame(r, c, size)) {
        cout << arr[r][c];
        return;
    }
    // 재귀식: 압축할 수 없으므로 작은 사이즈 호출하기
    cout << '(';
    compress(r, c, size/2);
    compress(r, c+size/2, size/2);
    compress(r+size/2, c, size/2);
    compress(r+size/2, c+size/2, size/2);
    cout << ')';
}

int main() {
    int n;
    cin >> n;
    fixed(cin);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    compress(0, 0, n);
}
