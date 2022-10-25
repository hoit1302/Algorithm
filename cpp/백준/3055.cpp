#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
/*
 * 탈출 https://www.acmicpc.net/problem/3055
 * 불 5427문제와 같은 아이디어
 *
 * 가장 주의해야할 부분은 초깃값을 -1로 설정해두었기 때문에
 * 77번째 줄에서 "물이 칸에 방문했을 때," 물이 고슴도치보다 빨리 또는 같은 시간에 왔다면 끊도록 조건을 작성해야한다.
 * 초깃값 -1은 항상 고슴도치 이동 시간보다 작을텐데
 * 이를 확인하지 않는다면 물이 방문하지 않은 경우에도 continue가 되어 탐색할 수 없다!
 */
int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> fr(r, vector<char>(c, 0));

    queue<ci> w_q, q;
    vector<vector<int>> w_dist(r, vector<int>(c, -1)); // 초기값 -1: 방문하지 않음
    vector<vector<int>> dist(r, vector<int>(c, -1)); // -1: 방문하지 않음.

    cin >> fixed;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> fr[i][j];
            if (fr[i][j] == '*') {
                w_q.push({i, j});
                w_dist[i][j] = 0;
            }
            if (fr[i][j] == 'S') {
                q.push({i, j});
                dist[i][j] = 0;
                fr[i][j] = '.'; // 물이 S칸으로 올 수 있도록
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!w_q.empty()) {
        auto [x, y] = w_q.front();
        w_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || r <= nx || c <= ny) continue;
            if (fr[nx][ny]!='.' || w_dist[nx][ny]!=-1) continue;
            w_q.push({nx, ny});
            w_dist[nx][ny] = w_dist[x][y] + 1;
        }
    }
    /*
     * debug
     */
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << w_dist[i][j] << ' ';
//        } cout << '\n';
//    } cout << '\n';

    int ans = 0;
    while (!q.empty() && !ans) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || r <= nx || c <= ny) continue;
            if (fr[nx][ny]=='D') {
                ans = dist[x][y] + 1;
                break;
            }
            if (fr[nx][ny]!='.' || dist[nx][ny]!=-1) continue;
            // 물이 언젠가 차는데, 고슴도치보다 먼저 탄다면 끊기
            if (w_dist[nx][ny]!=-1 && w_dist[nx][ny] <= dist[x][y] + 1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    /*
     * debug
     */
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << dist[i][j] << ' ';
//        } cout << '\n';
//    } cout << '\n';
    if (ans) {
        cout << ans;
    } else {
        cout << "KAKTUS";
    }
}