#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<int, int> ci;

vector<int> parent(101, -1);
vector<ci> stars;

int find(int a) {
    if (parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

bool uni(int a, int b) {
    int ap = find(a), bp = find(b);
    if (ap == bp) return false;
    if (abs(parent[ap]) < abs(parent[bp])) { // bp가 루트
        parent[bp] += parent[ap];
        parent[ap] = bp;
    } else {
        parent[ap] += parent[bp];
        parent[bp] = ap;
    }
    return true;
}

double kruskal(int n, vector<tp> &edges) {
    int cnt = 0;
    double sum = 0;
    for (auto [cost, a, b]: edges) {
        if (uni(a, b)) {
            sum += cost;
            cnt++;
        }
    }
    if (cnt == n - 1) {
        return sum;
    }
    return 0;
}
double calDist(int a, int b) {
    return sqrt(pow(abs(stars[a].first - stars[b].first), 2) +
                pow(abs(stars[a].second - stars[b].second), 2));
}
int main() {
    int n;
    float a, b;
    cin >> n;
    stars.assign(n, {});
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        stars[i] = {a, b};

    }
    vector<tp> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({calDist(i, j), i, j});
        }
    }
    sort(edges.begin(), edges.end());
    cout << fixed;  // 고정된 소수점 자리로 출력할 것을 선언
    cout.precision(2);  // 소수점 2번째자리로 정확도를 설정
    cout << kruskal(n, edges);
}