#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dis;

// mid 길이가 최대가 되려면 몇 번 잘라야하는지 구하기
int findCuttingCnt(int mid) {
    int ans = 0;
    for (int i = 0; i < dis.size(); i++) {
        if (dis[i] <= mid) continue; // 안자름
        ans += dis[i] / mid;
        if (dis[i] % mid == 0) {
            ans--;
        }
    }
    return ans;
}

int parametricSearch(int m) { // 초기값을 어떻게 설정해야하는거지??
    int s = 1, e = *dis.rbegin(), mid, ans;
    while (s <= e) {
        mid = (s + e) / 2;
        // cout << mid << "일 때, " << findCuttingCnt(mid)<< "회 자르면 됨\n";
        // 최댓값의 최솟값 문제. 훅 작아졌다가 슬슬 커져야 함.
        // 횟수와 나무토막 최대 길이 mid는 반비례한다!
        // 더 많이 자르면 안됨. 더 조금 잘라야함. 반대로 토막은 길어져야함.
        if (m < findCuttingCnt(mid)) {
            s = mid + 1;
        } else { // 더 적은 횟수로 잘랐음. 더 많이 잘라봐도 됨. 토막은 좀 더 짧아져보자
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> services(n);
    for (int i = 0; i < n; i++) {
        cin >> services[i];
    }
    services.push_back(0);
    services.push_back(l);
    sort(services.begin(), services.end());
    for (int i = 1; i <= n + 1; i++) {
        dis.push_back(services[i] - services[i - 1]);
    }
    sort(dis.begin(), dis.end());
//    for (int i = 0; i < dis.size(); i++) {
//        cout << dis[i] << ' ';
//    } cout << '\n';
    cout << parametricSearch(m) << '\n';
}