#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
typedef long long ll;

int calSame(ll h, ll s1, ll s2, deque<int> q1, deque<int> q2) {
    int cnt = 0;
    int size = q1.size() + 2 * q2.size();
    while (cnt < size) {
        // cout << s1 << ' ' << s2 << '\n';
        if (s1 == s2) {
            return cnt;
        }
        cnt++;
        if (s1 < h) {
            s1 += q2.front();
            s2 -= q2.front();
            q1.push_back(q2.front());
            q2.pop_front();
        } else {
            s1 -= q1.front();
            s2 += q1.front();
            q2.push_back(q1.front());
            q1.pop_front();
        }
    } return -1;
}

/*
 * https://school.programmers.co.kr/learn/challenges?partIds=31236
 * Lv. 2
 * 풀이 시간: 40분
 */
int solution(vector<int> queue1, vector<int> queue2) {
    ll s1 = 0, s2 = 0;
    for (int a: queue1) {
        s1 += a;
    }
    for (int a: queue2) {
        s2 += a;
    }
    if ((s1 + s2) % 2)
        return -1; // 홀수이면 불가능
    ll half = (s1 + s2) / 2;

    deque<int> q1(queue1.begin(), queue1.end()),
            q2(queue2.begin(), queue2.end());
    return calSame(half, s1, s2, q1, q2);
}
