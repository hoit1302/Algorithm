#include <iostream>
#include <vector>

using namespace std;

typedef pair<string, int> ci;
vector<ci> v;
int v_size;

string search(int p) {
    int s = 0, e = v_size - 1, mid;
    string ans = v[e].first;
    while (s < e) {
        mid = (s + e) / 2;
        if (p <= v[mid].second) { // 내 점수가 더 낮아, 이거 일 수도 있어
            e = mid;
            ans = v[mid].first;
        } else { // 내 점수가 더 높아 이거 일리 없음.
            s = mid + 1;
        }
    }
    return ans;
}
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string name;
    int n, m, cri, pre = -1, p;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name >> cri;
        if (pre == cri) continue;
        pre = cri;
        v.push_back({name, cri});
    }
    v_size = v.size();
    for (int i = 0; i < m; i++) {
        cin >> p;
        cout << search(p) << '\n';
    }
}