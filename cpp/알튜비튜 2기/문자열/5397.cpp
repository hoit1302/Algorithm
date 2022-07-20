#include <iostream>
#include <deque>

using namespace std;

/*
 * 키로거 [#](https://www.acmicpc.net/problem/5397)
 *
 * 틀린 이유(시간초과): 잘못된 접근
 *
 * 문자열 str.insert, str.erase 모두 O(N)의 시간 복잡도를 가짐
 * ans.erase(pos); // ans에 pos 인덱스 문자를 지운 결과가 저장됨.
 * ans.insert(ans.begin() + pos, in[i]); // ans에 pos 인덱스 위치에 문자를 추가한 결과가 저장됨.
 * deque로 삽입, 삭제 시 O(1)이 걸리도록 고침.
 */

void printPwd(deque<char> f, deque<char> b) {
    for (char ch : f) {
        cout << ch;
    }
    for (char ch : b) {
        cout << ch;
    }
    cout << '\n';
}

void findPwd(string in) {
    deque<char> f, b;

    for (size_t i = 0; i < in.size(); i++) {
        if (in[i] == '<') {
            if (!f.empty()) {
                b.push_front(f.back());
                f.pop_back();
            }
        } else if (in[i] == '>') {
            if (!b.empty()) {
                f.push_back(b.front());
                b.pop_front();
            }
        } else if (in[i] == '-') {
            if (!f.empty()) {
                f.pop_back();
            }
        } else {
            f.push_back(in[i]);
        }
//        printPwd(f, b);
    }
    printPwd(f, b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int tc;
    string in;
    cin >> tc;
    while (tc--) {
        cin >> in;
        findPwd(in);
    }
}
