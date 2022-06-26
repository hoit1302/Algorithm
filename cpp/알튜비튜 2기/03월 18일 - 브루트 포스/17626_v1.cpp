#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findMinNumber(int n, int num_size, vector<int> &square_num) {
    if (square_num[num_size - 1] == n) {
        return 1;
    }
    for (int i = num_size - 1; i >= 0; i--) {
        for (int j = num_size - 1; j >= 0; j--) {
            if (square_num[i] + square_num[j] == n) {
                return 2;
            }
        }
    }
    for (int i = num_size - 1; i >= 0; i--) {
        for (int j = num_size - 1; j >= 0; j--) {
            for (int k = num_size - 1; k >= 0; k--) {
                if (square_num[i] + square_num[j] + square_num[k] == n) {
                    return 3;
                }
            }
        }
    }
    return 4;
}

/**
 * [Four Squares] - 브루트포스 풀이 (8ms)
 * 자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
 * 미리 최댓값까지의 제곱수를 구해놓고, 완전탐색
 *
 * sqrt(50000) = 약 223
 * 전체 연산 수  < 223^2 + 223^3 = 11139296 <1억 -> 브루트포스 가능
 */

int main() {
    int n, num_size;
    vector<int> square_num;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++) {
        square_num.push_back(i * i);
    }
    num_size = square_num.size();
    cout << findMinNumber(n, num_size, square_num);
    return 0;
}