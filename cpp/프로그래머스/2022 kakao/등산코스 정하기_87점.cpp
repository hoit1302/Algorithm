#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, pair<int, int> > cii;
int parent[50001]; // -1: 그냥 부모, -2: 출입구, -3: 산봉우리, -6 출+산

int findParent(int a) {
    if (parent[a] < 0) return a;
    return parent[a] = findParent(parent[a]);
}
void uni(int a, int b, bool v) {
    int ap = findParent(a), bp = findParent(b);
    if (ap == bp) return;
    if (abs(parent[ap]) < abs(parent[bp])) { // bp가 부모
        parent[ap] = bp;
        if (v) parent[bp] = -6;
    } else {
        parent[bp] = ap;
        if (v) parent[ap] = -6;
    }
}

// 2차 시도, 구현 시간 1시간, MST Kruskal 알고리즘 사용, 87.1점
// 어려운 조건: intensity가 최소가 되는 등산코스가 여러 개라면 그중 산봉우리의 번호가 가장 낮은 등산코스를 선택합니다.
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    // parent 배열 초기화
    fill_n(parent, 50001, -1);
    for (int g: gates) {
        parent[g] = -2;
    }
    for (int p: summits) {
        parent[p] = -3;
    }
    // 1. cost가 낮은 간선부터 채택
    int p_size = paths.size();
    vector<cii> p(p_size);
    for (int i = 0; i < p_size; i++) {
        p[i] = {paths[i][2], {paths[i][0], paths[i][1]}};
    }
    sort(p.begin(), p.end());
    vector<int> ans(2);
    int max_w = 10000000;
    for (int i = 0; i < p_size; i++) {
        auto [cost, pos] = p[i];
        int ap = findParent(pos.first), bp = findParent(pos.second);
        // 4. 해당 intensity를 가진 간선까지 확인하여 더 작은 산봉우리로 정답 갱신
        if (max_w < cost) break;
        // 2. 합치면 안되는 조합: 출입구+출입구, 산봉우리+산봉우리
        if (parent[ap] * parent[bp] == 4 || parent[ap] * parent[bp] == 9) {
            continue;
        }
        // 3. 출입구 1개와 산봉우리 1개가 같은 그룹에 속하게 된다면 정답에 넣음.
        if (parent[ap] * parent[bp] == 6) {
            uni(pos.first, pos.second, true);
            ans[1] = cost;
            max_w = cost;
            continue;
        }
        uni(pos.first, pos.second, false);
    }
    for (int i = 1; i <= 50000; i++) {
        if (parent[i] == -6) {
            ans[0] = i;
            break;
        }
    }
    return ans;
}
