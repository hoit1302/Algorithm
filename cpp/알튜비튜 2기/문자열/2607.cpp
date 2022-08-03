#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0);
    for (int i = 0; i < str.size(); i++) {
        result[str[i] - 'A']++;
    }
    return result;
}

/**
 * 비슷한 단어 [#](https://www.acmicpc.net/problem/2607)
 * 비슷한 단어의 조건
 * 1. 같거나 한 문자를 더하거나, 빼면 같은 구성이 될 때
 *    -> 두 단어에서 다른 문자의 개수가 총 1개 이하
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 될 때
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> 이때, 두 단어의 길이가 같아야 함!
 */

int main() {
    int n, ans = 0;
    string source, target;
    cin >> n >> source;

    vector<int> source_alpha = alphaMap(source);
    while (--n) {
        cin >> target;

        int diff = 0;
        vector<int> target_alpha = alphaMap(target);
        for (int i = 0; i < SIZE; i++) {
            diff += abs(source_alpha[i] - target_alpha[i]);
        }
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}