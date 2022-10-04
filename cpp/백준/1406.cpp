#include <iostream>
#include <list>
using namespace std;

/*
 * 내가 짠 코드
 * 커서를 기점으로 오른쪽 왼쪽 2개의 list를 만들어 구현함.
 */
int main() {
    string str;
    cin >> str;
    list<char> r, l;
    for (char ch: str) {
        l.push_back(ch);
    }
    int cmd_cnt;
    cin >> cmd_cnt;
    char op, x;
    while (cmd_cnt--) {
        cin >> op;
        if (op == 'P') {
            cin >> x;
            l.push_back(x);
        } else if (op == 'L') {
            if (l.empty()) continue;
            r.push_front(l.back());
            l.pop_back();
        } else if (op == 'D') {
            if (r.empty()) continue;
            l.push_back(r.front());
            r.pop_front();
        } else {
            if (l.empty()) continue;
            l.pop_back();
        }
    }
    for (char ch: l) {
        cout << ch;
    }
    for (char ch: r) {
        cout << ch;
    } cout << '\n';
}

/*
 * 샘플 코드.
 * 1개의 리스트를 활용하고 cursor가 list의 포인터 역할을 하도록 구현함.
 */
int main() {
    string str;
    cin >> str;
    list<char> l;
    for (char ch: str) {
        l.push_back(ch);
    }
    auto cursor = l.end(); // cursor는 삽입될 수 있는 다음 빈 공간을 가리키고 있음.
    int cmd_cnt;
    cin >> cmd_cnt;
    char op, x;
    while (cmd_cnt--) {
        cin >> op;
        if (op == 'P') {
            cin >> x;
            l.insert(cursor, x); // cursor가 가리키는 곳 '앞'에 x 삽입
        } else if (op == 'L') {
            if (cursor != l.begin()) cursor--;
        } else if (op == 'D') {
            if (cursor != l.end()) cursor++;
        } else {
            // 커서가 가리키는 값을 제거하기 때문에
            if (cursor != l.begin()) {
                cursor--; // 전 칸으로 이동하고
                cursor = l.erase(cursor); // 가리키는 값을 지우고 그 '다음 원소'를 가리킴
            }
        }
    }
    for (char ch: l) {
        cout << ch;
    }
    for (char ch: r) {
        cout << ch;
    } cout << '\n';
}

