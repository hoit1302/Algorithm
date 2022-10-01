#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
typedef pair<int, int> ci;
string t[51][51];
ci parent[51][51];
vector<ci> child[51][51];

ci findParent(ci a) {
    if (a.first < 0 && a.second < 0) return a;
    return parent[a.first][a.second] = findParent(parent[a.first][a.second]);
}
void update(int r, int c, string value) {
    if (parent[r][c].first == 0) { // 병합되지 않음
        t[r][c] = value;
    }
    // 병합됨
    r = parent[r][c].first, c = parent[r][c].second;
    t[r][c] = value;
}

void updates(string v1, string v2) {
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            if (t[i][j] == v1)
                t[i][j] = v2;
        }
    }
}

void merge(int r1, int c1, int r2, int c2) {
    int rp1 = parent[r1][c1].first, cp1 = parent[r1][c1].second;
    int rp2 = parent[r2][c2].first, cp2 = parent[r2][c2].second;

    if (rp1 == 0) {
        rp1 = r1, cp1 = c1;
    }
    if (rp2 == 0) {
        rp2 = r2, cp2 = c2;
    }
    cout << "rp1 cp1의 밸류: " << rp1 << ' ' << cp1 << '\n';
    cout << "rp2 cp2의 밸류: " << rp2 << ' ' << cp2 << '\n';
    string value = t[rp1][cp1];
    cout << "r1 c1의 밸류: " << value << '\n';
    if (t[rp1][cp1].empty() && !t[rp2][cp2].empty()) {
        value = t[rp2][cp2];
    }
    int mxr = max(rp1, rp2), mxc = max(cp1, cp2);
    for (auto [i, j] : child[rp1][cp1]) { // 자식들 중 가장 큰 값 찾기
        if (mxr < i) mxr = i;
        if (mxc < j) mxc = j;
    }
    for (auto [i, j] : child[rp2][cp2]) { // 자식들 중 가장 큰 값 찾기
        if (mxr < i) mxr = i;
        if (mxc < j) mxc = j;
    }
    child[rp1][cp1].clear();
    child[rp2][cp2].clear();
    int mnr = min(rp1, rp2), mnc = min(cp1, cp2);
    cout << "mn: " << mnr << ' ' << mnc << '\n';
    cout << mnr << ' ' << mnc << ' ' << mxr << ' ' << mxc << '\n';
    for (int i = mnr; i <= mxr; i++) {
        for (int j = mnc; j <= mxc; j++) {
            if (i ==mnr && j == mnc) continue;
            parent[i][j] = {mnr, mnc};
            child[mnr][mnc].push_back({i, j});
            t[i][j] = "";
        }
    }
    parent[mnr][mnc] = {0, 0};
    t[mnr][mnc] = value;
}

void unmerge(int r, int c) {
    if (parent[r][c].first == 0) { // 병합되지 않음
        return;
    }
    int rp = parent[r][c].first, cp = parent[r][c].second;
    string v = t[rp][cp];
    for (auto [i, j] : child[rp][cp]) { // 자식의 부모 정보 삭제
        parent[i][j] = {0, 0};
        t[i][j] = "";
    }
    t[rp][cp] = "";
    child[rp][cp].clear(); // 부모의 자식 정보 삭제
    t[r][c] = v; // (r, c)에만 입력
}
string print(int r, int c) {
    if (parent[r][c].first == 0) { // 병합되지 않음
        return t[r][c].empty() ? "EMPTY" : t[r][c];
    }
    // 병합됨
    r = parent[r][c].first, c = parent[r][c].second;
    return t[r][c].empty() ? "EMPTY" : t[r][c];
}
void printtable() {
//    cout << "수행한거출력\n";
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << t[i][j] << ' ';
        } cout << '\n';
    }
}

// tc는 돌아감...;; & 틀린 부분 다시 찾아보기
vector<string> solution(vector<string> cmds) {
    vector<string> ans;
    string a, b, c, d, value;
    for (auto cmd: cmds) {
        stringstream ss(cmd);
        ss >> cmd >> a >> b;
        if (cmd == "PRINT") {
            ans.push_back(print(stoi(a), stoi(b)));
        } else if (cmd == "MERGE") {
            ss >> c >> d;
            merge(stoi(a), stoi(b), stoi(c), stoi(d));
        } else if (cmd == "UNMERGE") {
            unmerge(stoi(a), stoi(b));
        } else if (ss >> value) {
            update(stoi(a), stoi(b), value);
        } else {
            updates(a, b);
        }
        printtable();
    }
    return ans;
}
