#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, int c, vector<int> &element) {
    vector<int> brute(c + n - 1);
    fill(brute.begin() + c, brute.end(), 1);
    do {
        vector<int> res;
        int idx = 0;
        for (int i = 0; i < c + n - 1; i++) {
            if (brute[i]) {
                idx++;
            } else {
                res.push_back(element[idx]);
            }
        }
        for (int a: res) {
            cout << a << ' ';
        } cout << '\n';
    } while (next_permutation(brute.begin(), brute.end()));
}
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    solution(n, c, arr);
}