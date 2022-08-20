#include <iostream>
#include <vector>

using namespace std;

/*
 * 인구 이동 [#](https://www.acmicpc.net/problem/16234)
 *
 * 풀이 시간: 40분
 * 그래프 문제는 복잡하면 정말 좌절감이 많이 듬.
 * dfs에서 리턴값으로 원하는 값을 받을 순 있지만 80% 아리까리하게 이해한 것 같음.
 * 확실하게 이해해두는 건 해두고 구현할 때는 전역으로!!! 시간 없으니까.
 *
 * 각 단계에서 여러 그룹의 인구 이동이 일어날 수 있는데
 * 방문 처리를 했고
 * 같은 단계 내에서 한 그룹이 인구 이동을 해도 다른 그룹에는 영향을 미치지 않기에
 * 간단히 풀리는 문제이다.
 */

const int MAX = 100;
int population[MAX][MAX];
bool visited[MAX][MAX];
typedef pair<int, int> ci;
int n, l, r;
vector<ci> group;

void dfs(int i, int j) {
    visited[i][j] = true;
    group.push_back({i, j});

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir], ny = j + dy[dir];
        if (nx < 0 || ny < 0 || n <= nx || n <= ny) {
            continue;
        }
        int dif = abs(population[i][j] - population[nx][ny]);
        if (visited[nx][ny] || dif < l || r < dif) {
            continue;
        }
        // 탐색 가능
        dfs(nx, ny);
    }
}

void move(vector<ci> tmp) {
    int avg = 0;
    for (ci pos: tmp) {
        avg += population[pos.first][pos.second];
    }
    avg /= tmp.size();
    for (ci pos: tmp) {
        population[pos.first][pos.second] = avg;
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << population[i][j] << ' ';
//        } cout << '\n';
//    }
}

bool findGroup() {
    for (int i = 0; i < n; i++) {
        fill_n(visited[i], MAX, false);
    }

    bool is_change = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j])
                continue;
            // 시작점 가능

            group.clear();
            dfs(i, j);

            if (group.size() != 1) {
//                for (auto [a, b] : group) {
//                    cout << "(" << a << ", " << b << ") ";
//                } cout << '\n';
                is_change = true;
                move(group);
            }
        }
    }
    return is_change;
}

int main() {
    int ans = 0;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> population[i][j];
        }
    }

    while (findGroup()) {
        ans++;
    }
    cout << ans;
    return 0;
}