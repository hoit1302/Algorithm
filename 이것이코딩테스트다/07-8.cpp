#include <iostream>
#include <vector>

using namespace std;

// p. 201: 떡볶이 떡 만들기
vector<int> A;

long long sum_len(int mid) {
    long long res = 0LL;
    for (int i: A) {
        res += ((0 < (i - mid)) ? (i - mid) : 0);
    }
    return res;
}

int main() {
    freopen("../input.txt", "r", stdin);
    int N, M, a;
    cin >> N >> M;
    A.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> a;
        A[i] = a;
    }

    // 답으로 도출한 절단할 길이가 훅 작아졌다가 슬슬슬 커져야 함.
    // left, right, mid: 절단할 길이 관련, 특히, mid는 답으로 원하는 정보
    // M과 mid를 통해 계산된 sum은 범위를 조정하는데 필요한 정보
    int start = 0, end = 1000000000, mid, res = 0;
    while (start <= end) {
        mid = (start + end) / 2;
        long long total = sum_len(mid);

        if (M <= total) {
            start = mid + 1;
            res = mid;
        } else
            end = mid - 1;
    }
    cout << res;
    return 0;
}
