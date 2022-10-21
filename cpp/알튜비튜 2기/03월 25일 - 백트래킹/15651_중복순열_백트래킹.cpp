#include <iostream>
#include <vector>

using namespace std;
/*
 *n 파이 r 중복 순열
 */
void solution(int depth, vector<int> res, int n, int c, vector<int> &element) {
    if (depth == c) {
        for (auto r: res) {
            cout << r << ' ';
        } cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        res.push_back(element[i]);
        solution(depth + 1, res, n, c, element);
        res.erase(--res.end());
    }
}
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    vector<int> res;
    solution(0, res, n, c, arr);
}