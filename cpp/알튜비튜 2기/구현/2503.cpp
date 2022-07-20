#include <iostream>
#include <vector>
#include <algorithm>

/*
 * 숫자 야구 [#](https://www.acmicpc.net/problem/2503)
 * 처음 제출 (32분)까지 시간이 걸린 이유: for loop i, j 실수!!!
 * 틀린 이유: 문제에서 빠뜨린 조건. 세 자리 수는 1~9, 서로 다른 수
 * 순열, 조합 등 어느 문제인지 파악하고 stl을 활용해 구현하는 방법 익히기
 */
using namespace std;
typedef pair<int, int> ci;

struct game {
    string num;
    int st, b;
};

vector<game> games;

ci calScore(string a, string b) {
//    cout << a <<"와 " << b << "의 결과는 ";
    int st = 0, ba = 0;
    // strike 확인, strike이면 개수 높이고 방문했다고 기록.
    for (int i = 0; i < 3; i++) {
        if (a[i] == b[i]) {
            st++;
            a[i] = '.';
            b[i] = '.';
        }
    }
    // 남은 숫자들에 대해서 ball 확인
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i] == '.' || b[j] == '.') {
                continue;
            }
            if (a[i] == b[j]) {
                ba++;
                a[i] = '.';
                b[j] = '.';
            }
        }
    }
//    cout << st << " " << ba << '\n';
    return {st, ba};
}

bool isPs(string num, int size) {
    for (int i = 0; i < size; i++) {
        auto [st, b] = calScore(num, games[i].num);
        if (games[i].st != st || games[i].b != b) {
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    games.assign(n, {});
    for (int i = 0 ; i < n; i++) {
        cin >> games[i].num >> games[i].st >> games[i].b;
    }
    int ans = 0;
    string permutation = "123456789";
    do {
        string tmp = "";
        for (int i = 0; i < 3; i++) {
            tmp.append(1, permutation[i]);
        }
        // cout << tmp << '\n';
        reverse(permutation.begin() + 3, permutation.end()); // ✨✨✨
        if (isPs(tmp, n)) {
            ans++;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));
    cout << ans << '\n';
}