#include <iostream>
#include <map>
#include <vector>

using namespace std;

int jumpCar(int n, vector<string> &out_car, map<string, int> &m) {
    int ans = 0;
    for (int i = 0; i < n; i++) { // 나온 차순 == 나
        for (int j = i + 1; j < n; j++) { // 나보다 늦게 나온 차들 검사
            if (m[out_car[i]] > m[out_car[j]]) { // 나보다 늦게 '나온' 차가 사실은 먼저 들어온 차였다면 -> 내가 추월했음.
                ans++;
                break; // 추월을 했는지 안 했는지만 보는 것이기 때문에 바로 break
            }
        }
    }
    return ans;
}

int main() {
    int n;
    string car;
    map<string, int> m;

    cin >> n;
    for (int i = 1; i <= n; i++) { // 들어오는 차
        cin >> car;
        m[car] = i; // 들어가는 순서 저장
    }
    vector<string> out_car(n, ""); // 나온 차
    for (int i = 0; i < n; i++) {
        cin >> out_car[i];
    }

    cout << jumpCar(n, out_car, m);
    return 0;
}