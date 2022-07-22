#include <string>
#include <vector>
#include <map>

using namespace std;

/*
 * 접근: sliding window (size=10)로 이동하면서 정현이가 원하는 것 이상을 만족하는지 확인
 * 풀이 시간: 25분
 */

bool isPs(map<string, int> jh, map<string, int> mt) {
    for (auto [jh_w, jh_n] : jh) {
        if (jh_n == 0) {
            continue;
        }
        if (mt[jh_w] < jh[jh_w]) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    // 1. 정현이가 원하는 제품과 제품의 수량 저장
    map<string, int> jh, mt;
    for (size_t i = 0; i < number.size(); i++) {
        jh[want[i]] = number[i];
    }

    // 2.
    // 2-1. 초기화
    for (int i = 0; i < 10; i++) {
        mt[discount[i]]++;
    }
    // 2-2. 확인 후 이동
    size_t dis_size = discount.size();
    int ans = 0;
    for (size_t i = 0; i < dis_size - 9; i++) {
        if (isPs(jh, mt)) { // 확인
            ans++;
        }
        if (i + 10 == dis_size) { // idx 에러 방지
            break;
        }
        mt[discount[i]]--; // 이동
        mt[discount[i + 10]]++;
    }
    return ans;
}