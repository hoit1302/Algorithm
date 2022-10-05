#include <iostream>
#include <stack>

using namespace std;
const int INF = 100000001;
int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, h;
    cin >> n;
    stack<pair<int, int>> st;
    st.push({INF, 0});
    for (int i = 1; i <= n; i++) {
        cin >> h;
        while (st.top().first < h) {
            st.pop();
        }
        cout << st.top().second << ' ';
        st.push({h, i});
    } cout << '\n';
}