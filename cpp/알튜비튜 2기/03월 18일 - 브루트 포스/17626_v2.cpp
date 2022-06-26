#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, num_size;
vector<int> square_num;

bool isPossible(int cnt, int sum, int m) { //cnt: 고른 개수, sum: 지금까지 합, m: 골라야 하는 개수
    bool check = false;

    if (cnt == m) {
        if (sum == n) {
            return true;
        }
        return false;
    }
    // 제곱수가 큰 수부터 검사해서 더한 값이 n 넘어가면 가지치기
    for (int i = num_size - 1; i >= 0; i--) {
        if (sum + square_num[i] <= n) {
            check = isPossible(cnt + 1, sum + square_num[i], m);
            if (check) {
                return true;
            }
        }
    }
    return check;
}

/**
 * [Four Squares] - 백트래킹 풀이 (8ms)
 * 자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
 * 미리 최댓값까지의 제곱수를 구해놓고, 1개 ~ 3개까지의 제곱수 합으로 표현이 가능한지 검사
 */

int main() {
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++) {
        square_num.push_back(i * i);
    }
    num_size = square_num.size();

    int ans = 4;
    for (int i = 1; i <= 3; i++) {
        if (isPossible(0, 0, i)) {
            ans = i;
            break;
        }
    }

    cout << ans;
    return 0;
}