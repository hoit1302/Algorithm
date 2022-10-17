#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e5;
int n,m,cctv_cnt = 0, mn = INF;
typedef pair<int, int> ci;
typedef vector<vector<int>> mt;
vector<pair<int, int>> cctvs;
int calEmptySpace(mt room) {
    int empty_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (0 == room[i][j]) {
                empty_cnt++;
            }
        }
    } return empty_cnt;
}

mt monitor(int x, int y, vector<ci> dirs, mt room) {
    for (auto [dx, dy]: dirs) {
        int nx = x, ny = y;
        while (true) {
            nx += dx, ny += dy;
            if (nx < 0 || ny < 0 || n <= nx || m <= ny) break;
            if (room[nx][ny] == 6) break;
            if (room[nx][ny] != 0) continue;
            room[nx][ny] = 10; // 칠해짐
        }
    }
    return room;
}

void simul(int dp, mt room) {
    if (cctv_cnt <= dp) {
        mn = min(mn, calEmptySpace(room));
        return;
    }
    ci d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 상부터 시계방향
    auto [x, y] = cctvs[dp];
    if (room[x][y] == 1) {
        for (int dir = 0; dir < 4; dir++) {
            simul(dp+1, monitor(x, y, {d[dir]}, room));
        }
    } else if (room[x][y] == 2) {
        simul(dp+1, monitor(x, y, {d[0], d[2]}, room));
        simul(dp+1, monitor(x, y, {d[1], d[3]}, room));
    } else if (room[x][y] == 3) {
        simul(dp+1, monitor(x, y, {d[0], d[1]}, room));
        simul(dp+1, monitor(x, y, {d[1], d[2]}, room));
        simul(dp+1, monitor(x, y, {d[2], d[3]}, room));
        simul(dp+1, monitor(x, y, {d[3], d[0]}, room));
    } else if (room[x][y] == 4) {
        simul(dp+1, monitor(x, y, {d[1], d[2], d[3]}, room));
        simul(dp+1, monitor(x, y, {d[0], d[2], d[3]}, room));
        simul(dp+1, monitor(x, y, {d[0], d[1], d[3]}, room));
        simul(dp+1, monitor(x, y, {d[0], d[1], d[2]}, room));
    } else if (room[x][y] == 5) {
        simul(dp+1, monitor(x, y, {d[0], d[1], d[2], d[3]}, room));
    }
}

int main() {
    cin >> n >> m;
    mt room(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
            if (0 < room[i][j] && room[i][j] < 6) {
                cctv_cnt++;
                cctvs.push_back({i, j});
            }
        }
    }
    simul(0, room);
    cout << mn;
}
/*
 * cctv 감시 후 변경된 매트릭스 정보를 함수 리턴값으로 가져오도록 구현했다.
 * 그리고 바로 다음 cctv에 대해 탐색할 수 있도록 했다.
 */