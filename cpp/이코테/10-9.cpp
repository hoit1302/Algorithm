#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// p. 303: 커리큘럼
// 위상 정렬
// 시간은 오래걸렸지만 답안과 똑같게!!! 구현함~~, 기억 안 날 때 다시 풀어보기!!!
int main() {
    freopen("../input.txt", "r", stdin);
    int N;
    int time[501] = {0,}; // 각 강의 시간
    int topol[501] = {0,}; // 자신에게 "들어오는" 간선의 수, 0이면 큐에 삽입
    int total_time[501] = {0,}; // 정답 배열, 초기화는 해당 강의의 시간
    cin >> N;
    vector<vector<int> > graph(500 + 1); // 그래프 정보: from A to B
    for (int i = 1; i <= N; i++) {
        cin >> time[i];
        int tmp;
        while (true) {
            cin >> tmp;
            if (tmp == -1) break;
            topol[i]++;
            graph[tmp].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (topol[i] == 0) {
            q.push(i);
            total_time[i] = time[i];
        }
    }
    while (!q.empty()) {
        int from = q.front(); // 들어오는 간선 수가 0개임.
        q.pop();
        for (int to: graph[from]) {
            total_time[to] = max(total_time[to], time[to] + total_time[from]);
            topol[to]--;
            if (topol[to] == 0)
                q.push(to);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << total_time[i] << "\n";
    return 0;
}