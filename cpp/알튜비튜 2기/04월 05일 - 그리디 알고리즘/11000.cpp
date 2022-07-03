#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int findCourseCnt(int n, vector<ci> &courses) {
    priority_queue<int, vector<int>, greater<> > pq; // min_heap, 끝나는 시간
    pq.push(courses[0].second);
    for (int i = 1; i < n; i++) {
        if (pq.top() <= courses[i].first) {
            pq.pop();
        }
        pq.push(courses[i].second);
    }
    return pq.size();
}

int main() {
    int n;
    cin >> n;
    vector<ci> courses(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> courses[i].first >> courses[i].second;
    }

    // 강의실 수를 최소로 하기 위해서, 현재 사용하는 강의실 중 가장 빨리 끝나는 강의실에 가장 먼저 시작하는 강의실을 배치해야 한다.
    sort(courses.begin(), courses.end()); // 일찍 시작하는 것부터 배치해야함.
    cout << findCourseCnt(n, courses) << '\n';
}