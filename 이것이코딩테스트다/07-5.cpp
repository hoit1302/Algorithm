#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// p. 197: 부품 찾기
vector<int> A;

int find(int N, int a) {
    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (A[mid] == a)
            return mid;
        if (A[mid] < a) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, a;
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> a;
        A[i] = a;
    }
    sort(A.begin(), A.end());
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> a;
        if (find(N, a) == -1)
            cout << "no ";
        else
            cout << "yes ";
    }
    cout << "\n";
    return 0;
}
