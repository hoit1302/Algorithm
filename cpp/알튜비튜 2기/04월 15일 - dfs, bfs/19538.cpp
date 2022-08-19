#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<vector<int>> E, int M, vector<int> firstInfected) {
    queue<int> q;
    vector<int> answer(N, -1);
    vector<int> turn(N + 1);

    for (int t : firstInfected) {
        q.push(t);
        answer[t - 1] = 0;
    }

    for (int i = 1; i <= N; i++)
        turn[i] = E[i].size() / 2;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : E[current]) {
            if (next == 0) break;
            turn[next] -= 1;
            if (answer[next - 1] == -1 && turn[next] <= 0) {
                q.push(next);
                answer[next - 1] = answer[current - 1] + 1;
            }
        }
    }

    return answer;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> E(N + 1);
    for (int i = 1; i <= N; i++) {
        while (1) {
            int t;
            cin >> t;
            E[i].push_back(t);
            if (t == 0) break;
        }
    }

    int M;
    cin >> M;
    vector<int> firstInfected(M);
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        firstInfected.push_back(t);
    }

    vector<int> ans = solution(N, E, M, firstInfected);
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << "\n";
}