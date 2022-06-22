#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << "0";
        return 0;
    }
    priority_queue<int> pq; // 기본적으로 큰 수가 먼저 튀어나오는 구조로 설계됨. 따라서 -를 효율적으로 잘 붙여주어야 함.
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        pq.push(-tmp);
    }

    int res = 0;
    for (int i = 0; i < N - 1; i++) {
        int first = -pq.top(); pq.pop();
        int second = -pq.top(); pq.pop();
//        cout << first << " " << second;
        res += first + second;
        pq.push(-(first + second));
    }
    cout << res << "\n";
    return 0;
}