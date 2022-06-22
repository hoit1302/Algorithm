#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 이분탐색을 이용한 풀이
 * O(n)의 시간복잡도를 갖는 선형탐색(linear search)과 달리,
 * 이분탐색(binary search)는 O(logn)의 시간 복잡도를 갖습니다.
 * */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, input;

        cin >> n;
        vector<int> note1(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> note1[i];
        }

        // 이분탐색을 하기 위해 정렬
        sort(note1.begin(), note1.end());

        cin >> m;
        while (m--) {
            cin >> input;
            // 이분탐색 라이브러리 함수를 활용해, 원소가 수첩1에 있는지 확인
            // binary_search() -> 이분탐색으로 원소가 있는지를 확인하고, 결과를 리턴하는 함수
            if (binary_search(note1.begin(), note1.end(), input)) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
    return 0;
}