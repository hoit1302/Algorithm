#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

vector<ci> people;

/**
 * 서류심사가 1등인 0번 인덱스 사람은 무조건 합격이므로 1번 인덱스부터 검사
 * 현재 인덱스 사람은 서류심사 순위가 그 다음 인덱스 사람들보다 무조건 위
 * 따라서 그 전 사람들(서류심사가 현재 사람보다 높은)보다 면접심사가 높으면 합격
 */
int getMaxRes(int n) {
    int res = n;
    int first_rank = people[0].second;
    for (int i = 1; i < n; i++) {
        if (first_rank < people[i].second)
            res--;
        else {
            first_rank = people[i].second;
        }
    }
    return res;
}

// 수아님 코드
int cntEmploy(int n, vector<ci> rank) {
    int ans = 1, first_rank = rank[0].second;
    for (int i = 1; i < n; i++) {
        if (first_rank > rank[i].second) {
            first_rank = rank[i].second;
            ans++;
        }
    }
    return ans;
}


int main() {
    int tc, n;

    cin >> tc;
    while (tc--) {
        cin >> n;
        people.assign(n, ci(0, 0));
        for (int i = 0; i < n; i++) {
            cin >> people[i].first >> people[i].second;
        }
        sort(people.begin(), people.end());

        cout << getMaxRes(n) << '\n';
    }
    return 0;
}
