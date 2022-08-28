#include <iostream>
#include <algorithm>

using namespace std;

int seq[2000];
bool isGood(int idx, int size) {
//    cout << seq[idx] << ": \n";
    int s = 0, e = size - 1;
    while (s < e) { // s != e 라는 조건 때문에
        if (s == idx) {
            s++;
        }
        if (e == idx) {
            e--;
        }
        if (size <= s || e < 0 || s == e) {
            break; // idx 변경 후 범위와 조건 확인
        }
//        cout << seq[s] << ", " << seq[e] << '\n';
        if (seq[s] + seq[e] < seq[idx]) {
            s++;
        } else if (seq[s] + seq[e] > seq[idx]) {
            e--;
        } else {
            return true;
        }
    } return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    sort(seq, seq + n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (isGood(i, n)) {
            res++;
        }
    }
    cout << res << '\n';
}