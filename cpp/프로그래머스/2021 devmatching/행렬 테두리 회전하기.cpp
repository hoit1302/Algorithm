#include <vector>

using namespace std;
/*
 * 풀이시간: 32분, 한 칸씩 이동시키는 로직 작성 오래 걸림.
 * 단순한 로직이지만 자칫 잘못하면 시간이 오려걸림. 여러 번 생각해보자.
 */
int g[101][101];
typedef pair<int, int> ci;
pair<int, vector<ci>> findMin(int x1, int y1, int x2, int y2) {
    vector<ci> o;
    int mn = 10001;
    // 1. 위
    for (int i = y1; i <= y2; i++) {
        o.push_back({x1, i});
        mn = min(mn, g[x1][i]);
    }
    // 2. 오른쪽
    for (int i = x1 + 1; i < x2; i++) {
        o.push_back({i, y2});
        mn = min(mn, g[i][y2]);
    }
    // 3. 아래
    for (int i = y2; i >= y1; i--) {
        o.push_back({x2, i});
        mn = min(mn, g[x2][i]);
    }
    // 4. 왼쪽
    for (int i = x2 - 1; i > x1; i--) {
        o.push_back({i, y1});
        mn = min(mn, g[i][y1]);
    }
    o.push_back({x1, y1});
    return {mn, o};
}

void rotate(vector<ci> &arr) {
    int dis, pre = g[arr[0].first][arr[0].second];
    for (int i = 1; i < arr.size(); i++) {
        int x2 = arr[i].first, y2 =  arr[i].second;
        dis = g[x2][y2]; // 2. (x2, y2) 갱신 전에 저장해둠.
        g[x2][y2] = pre; // 1. (x2, y2) 값이 이전 값으로 갱신됨.
        pre = dis; // 3. 다음 번 for 문에서 이전 값으로 활용되도록 갱신해줌.
    }
    return;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int k = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            g[i][j] = k++;
        }
    }
    vector<int> ans;
    for (auto q: queries) {
        auto [min, rot_arr] = findMin(q[0], q[1], q[2], q[3]);
        ans.push_back(min);
        rotate(rot_arr);
    }
    return ans;
}