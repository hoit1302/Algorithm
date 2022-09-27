#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, ex, ey;
int calDist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isPossible(int nx, int ny, int k) {
    if (nx < 0 || ny < 0 || n <= nx || m <= ny) // 범위 벗어남
        return false;
    if (k < calDist(nx, ny, ex, ey)) // 어떻게 가도 닿을 수 없음
        return false;
    return true;
}

/*
 * dlru 순서대로 길을 찾는데 갈 수 있다면 가버리기!
 */
string solution(int nn, int mm, int x, int y, int r, int c, int k) {
    n = nn, m = mm , ex = r-1, ey = c-1;

    string dir = "dlru";
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    x--, y--;
    int kk = k;
    string ans;
    for (int a = 0; a < kk; a++) {
        bool f = false; // 길이 있니?
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i], nk = k - 1;
            if (isPossible(nx, ny, nk)) {
                ans.append(1, dir[i]);
                f = true;
                x = nx, y = ny, k = nk;
                break;
            }
        }
        if (!f) {
            return "impossible";
        }
    }
    return ans;
}

int main() {
    cout << solution(3, 4, 2, 3, 3, 1, 5) << '\n';
    cout << solution(2, 2, 1, 1, 2, 2, 2) << '\n';
    cout << solution(3, 3, 1, 2, 3, 3, 4) << '\n';
}