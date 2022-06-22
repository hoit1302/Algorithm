#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

class Virus {
public:
    int x;
    int y;
    int kind;
    int time;

    Virus(int x, int y, int kind, int time) {
        this->x = x;
        this->y = y;
        this->kind = kind;
        this->time = time;
    }

    // 주의 백만개 const 모두 붙이기!
    bool operator <(const Virus &other) const {
       return this->kind < other.kind;
    }
};

int main() {
    freopen("../input.txt", "r", stdin);
    int N, K, S, X, Y;
    int graph[200][200];
    cin >> N >> K;
    vector<Virus>first_virus_info;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != 0)
                first_virus_info.push_back(Virus(i, j, graph[i][j], 0));
        }
    }
    sort(first_virus_info.begin(), first_virus_info.end());
    cin >> S >> X >> Y;

    queue<Virus> q;
    for (auto first: first_virus_info) {
        q.push(first);
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.x, ny = dy[i] + cur.y;
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (graph[nx][ny] == 0 && cur.time + 1 <= S) { // 갱신이 필요할 때만! 갱신하고 집어넣음
                    graph[nx][ny] = cur.kind;
                    q.push(Virus(nx, ny, cur.kind, cur.time + 1));
                }
            }
        }
    }

    // result
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout << graph[i][j] << " ";
//        } cout << "\n";
//    }
    cout << graph[X - 1][Y - 1] << "\n";
    return 0;
}