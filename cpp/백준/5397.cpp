#include <iostream>
#include <list>
using namespace std;
string getRes(string input) {
    list<char> l;
    auto cursor = l.end(); // l.begin(), l.end() 같은 곳
    for (auto ch: input) {
        if (isalnum(ch)) {
            l.insert(cursor, ch); // 커서 앞에 ch 삽입
        } else if (ch == '<') {
            if (cursor != l.begin()) cursor--;
        } else if (ch == '>') {
            if (cursor != l.end()) cursor++;
        } else {
            if (cursor != l.begin()) {
                // 커서가 가리키는 값을 삭제하니
                // 살제할 원소로 이동
                cursor--;
                // 삭제한 원소 다음 위치 반환
                cursor = l.erase(cursor);
            }
        }
    }
    string ans;
    for (auto a: l) {
        ans.append(1, a);
    } return ans;
}
int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        cout << getRes(str) << '\n';
    }
}