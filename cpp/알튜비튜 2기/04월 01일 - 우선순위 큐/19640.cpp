#include <iostream>
#include <queue>

using namespace std;

struct em {
    int d, h, line;
    bool isDeka;
};

bool operator <(em a, em b) {
    if (a.d != b.d)
        return a.d < b.d; // 높은 게 먼저
    if (a.h != b.h)
        return a.h < b.h; // 높은 게 먼저
    return a.line > b.line; // 낮은 게 먼저
}

int main() {
    int n, m, k, d, h, line;
    cin >> n >> m >> k;
    // 사원 수보다 줄 수가 많을 때 줄 수를 줄여도 무방, 런타임 에러 방지
    if (n < m) {
        m = n;
    }
    vector<queue<em>> ems(m);
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        line = i % m;
        if (i == k) {
            ems[line].push({d, h, line, true});
            continue;
        }
        ems[line].push({d, h, line, false});
    }
    // 큐에서 가장 앞을 꺼내서 우선순위큐 돌리고 나온 친구가 데카인지, 아니면 ans++ 반복
    priority_queue<em, vector<em> > pq;
    for (int i = 0; i < m; i++) {
        pq.push(ems[i].front());
        ems[i].pop();
    }

    int ans = 0;
    while (!pq.empty()) {
        em employee = pq.top(); pq.pop();
        // cout << employee.d << ' ' << employee.h << ' ' << employee.line << ' ' << employee.isDeka << '\n';
        if (employee.isDeka) {
            break;
        }
        // 데카가 아님. 다른 사람이 화장실에 들어갔음. 선두인 그룹 갱신
        ans++;
        if (!ems[employee.line].empty()) {
            pq.push(ems[employee.line].front()); ems[employee.line].pop();
        }
    }
    cout << ans << '\n';
}