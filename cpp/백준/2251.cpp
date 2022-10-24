#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> ti;
bool vst[201][201][201];
pair<int, int> pourAtoB(int a, int b, int b_t) {
    // 1. b에 모두 담을 수 있을 때
    if (a + b <= b_t) {
        return {0, a + b};
    }
    // 2. b에 전혀 담을 수 없을 때
    if (b == b_t) {
        return {a, b};
    }
    // 3. b에 담고도 a가 남을 때
    return {a - (b_t- b), b_t};
}
int main() {
    cout.tie(0), ios_base::sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    queue<ti> q;
    q.push({0, 0, c});
    vst[a][b][c] = true;
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        int nx, ny, nz;
        // 1. C에서 B에 쏟아 붓는 경우
        tie(nz, ny) = pourAtoB(z, y, b);
        if (!vst[x][ny][nz]) {
            q.push({x, ny, nz});
            vst[x][ny][nz] = true;
        }
        // 2. C에서 A에 따르는 경우
        tie(nz, nx) = pourAtoB(z, x, a);
        if (!vst[nx][y][nz]) {
            q.push({nx, y, nz});
            vst[nx][y][nz] = true;
        }
        // 3. A에서 B로 따르는 경우
        tie(nx, ny) = pourAtoB(x, y, b);
        if (!vst[nx][ny][z]) {
            q.push({nx, ny, z});
            vst[nx][ny][z] = true;
        }
        // 4. A에서 C로 따르는 경우
        tie(nx, nz) = pourAtoB(x, z, c);
        if (!vst[nx][y][nz]) {
            q.push({nx, y, nz});
            vst[nx][y][nz] = true;
        }
        // 5. B에서 A로 따르는 경우
        tie(ny, nx) = pourAtoB(y, x, a);
        if (!vst[nx][ny][z]) {
            q.push({nx, ny, z});
            vst[nx][ny][z] = true;
        }
        // 6. B에서 C로 따르는 경우
        tie(ny, nz) = pourAtoB(y, z, c);
        if (!vst[x][ny][nz]) {
            q.push({x, ny, nz});
            vst[x][ny][nz] = true;
        }
    }
    for (int i = 0; i <= c; i++) {
        for (int j = 0; j <= b; j++) {
            if (vst[0][j][i]) {
                cout << i << ' ';
                break;
            }
        }
    } cout << '\n';
}