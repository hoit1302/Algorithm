#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
vector<int> info;
vector<vector<int>> tree;
void sheep(int cur, int s_cnt, int w_cnt, vector<int> &remain) {
    if (info[cur] == 0)
        s_cnt++;
    else
        w_cnt++;
    if (s_cnt <= w_cnt) return;
    ans = max(ans, s_cnt);
    // debug
//    cout << "현재 노드는 " << cur << "이고, 센 양과 늑대 개수는 " << s_cnt << ' ' << w_cnt << "\n앞으로 방문할 정점은 ";
//    for (int r: remain) {
//        cout << r << ' ';
//    } cout << '\n';


    for (int i = 0; i < remain.size(); i++) {
        int nxt = remain[i];
        // 다음에 방문할 노드 배열 재생성
        vector<int> n_r = remain;
        n_r.erase(n_r.begin() + i);
        for (int child: tree[nxt]) {
            n_r.push_back(child);
        }
        sheep(nxt, s_cnt, w_cnt, n_r);
    }

}
int solution(vector<int> in, vector<vector<int>> edges) {
    info = in;
    tree.assign(info.size(), vector<int>());
    for (vector<int> e: edges) {
        tree[e[0]].push_back(e[1]);
    }
    vector<int> remain;
    for (int nxt: tree[0]) {
        remain.push_back(nxt);
    }
    sheep(0, 0, 0, remain);
    return ans;
}

//int main() {
//    vector<int> in = {0,0,1,1,1,0,1,0,1,0,1,1};
//    vector<vector<int>> edges = {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};
//    solution(in, edges);
//}