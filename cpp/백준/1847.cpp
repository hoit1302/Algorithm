#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, e;
    vector<char> op;
    cin >> n;
    stack<int> st;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        cin >> e;
        while (cnt <= e) {
            st.push(cnt++);
            op.push_back('+');
        }
        if (e != st.top()) {
            cout << "NO\n";
            return 0;
        }
        st.pop();
        op.push_back('-');
    }
    for (char ch: op) {
        cout << ch << '\n';
    }
}
/*
 * 입20번째 줄에서 생각하기
 * st이 빈 경우는 없을까?
 * 력받은 수만큼 st에 push된 상태임을 보장하고
 * 오류를 바로 확인해 리턴시키므로 없음.
 * 3 1 2의 경우를 생각하면, 1,2,3넣고 3뺌, top이 2라 오류임 바로 no 리턴
 */