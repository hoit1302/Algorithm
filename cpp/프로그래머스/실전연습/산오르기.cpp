#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e9;
// 문제에 주어진 테케는 맞췄는데 정말 풀어낸건지는 확신할 수 없음.
// 아직 틀린 테케는 못찾음, 내일 하루 더 살펴보기
// isIn 함수: 범위 내에 있고 아직 방문하지 않았다면 true를 리턴하는 함수
// BFS는 처음 방문하는 것이 최단 거리임을 보장함!!! 그러므로 INF보다 -1로 값을 초기화하는 것이 더 가독성 높아짐!!!
// 좌우로 2~3칸 움직이는 로직을 개선시키고 싶음 ㅠ0ㅠ

int n, m;
vector<string> w;
vector<vector<int>> dist;

bool isIn(int nx, int ny) {
    if (nx < 0 || ny < 0 || n <= nx || m <= ny || dist[nx][ny] != INF)
        return false;
    return true;
}
vector<ci> calNxt(int x, int y) {
    vector<ci> nxts;
    int nx, ny;
    // 1. 상하좌우 인접
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (!isIn(nx, ny)) continue;
        if (w[nx][ny] == 'H') {
            nxts.push_back({nx, ny});
        }
    }

    // 2. 좌우로 2~3칸 떨어짐
    int yy[4] = {2, 3, -2, -3};
    for (int i = 0; i < 4; i++) {
        ny = y + yy[i];
        if (!isIn(x + 1, ny)) continue;
        if (w[x][ny] != 'H') continue;
        bool flag = true;
        if (y < ny) {
            for (int j = y; j <= ny; j++) {
                if (w[x + 1][j] != '.') {
                    flag = false;
                }
            }
            for (int j = y + 1; j <= ny - 1; j++) {
                if (w[x][j] != '.') {
                    flag = false;
                }
            }
        } else {
            for (int j = ny; j <= y; j++) {
                if (w[x + 1][j] != '.') {
                    flag = false;
                }
            }
            for (int j = ny + 1; j <= y - 1; j++) {
                if (w[x][j] != '.') {
                    flag = false;
                }
            }
        }
        if (flag)
            nxts.push_back({x, ny});
    }

    // 3. 위쪽 (-> 아래쪽)이 빈칸이고 그 위가 홀드인 경우
    if (isIn(x+2, y) && w[x+1][y] == '.' && w[x+2][y]=='H') {
        nxts.push_back({x + 2, y});
    }
    // 4. 오른쪽 위 -> 오른쪽 아래
    nx = x + 1; ny = y + 1;
    if (isIn(nx, ny) && w[x][ny] == '.' && w[nx][y] == '.' && w[nx][ny] == 'H') {
        nxts.push_back({nx, ny});
    }
    // 5. 왼쪽 위 -> 왼쪽 아래
    nx = x + 1; ny = y - 1;
    if (isIn(nx, ny) && w[x][ny] == '.' && w[nx][y] == '.' && w[nx][ny] == 'H') {
        nxts.push_back({nx, ny});
    }
    return nxts;
}

vector<vector<int>> solution(vector<string> wall) {
    w = wall;
    n = wall.size(), m = wall[0].size();
    reverse(w.begin(), w.end());
    dist.assign(n, vector<int>(m, INF));
    queue<ci> q;
    dist[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        auto nxts = calNxt(x, y); // 갈 수 있는 다음 홀드
        for (auto [nx, ny]: nxts) {
            if (dist[nx][ny] <= dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    // 리턴 배열 설정
    reverse(dist.begin(), dist.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (wall[i][j] == '.' || wall[i][j] == 'X') {
                dist[i][j] = 0;
                cout << dist[i][j] << ' '; // debug
                continue;
            }
            if (dist[i][j] == INF)
                dist[i][j] = -1;
            cout << dist[i][j] << ' '; // debug
        } cout << '\n'; // debug
    }
    return dist;
}

int main() {
    vector<string> wall = {"....HH", "H..H.X"};
    solution(wall);
}
