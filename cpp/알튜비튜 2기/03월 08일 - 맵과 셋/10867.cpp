#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, input;
    set<int> s;

    cin >> n;
    while (n--) {
        cin >> input;
        s.insert(input);
    }

    //초기화 값에 따라 데이터 타입을 자동으로 정해주는 auto 연산자 활용
    for (auto iter = s.begin(); iter != s.end(); iter++) { // 반복자를 사용하여 set 순회
        cout << *iter << ' ';
    }
    return 0;
}