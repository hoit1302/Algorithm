#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> keys;
map<string, vector<int> > scores;
vector<vector<string>> types = {{"cpp", "java", "python"}, {"backend", "frontend"}, {"junior", "senior"}, {"chicken", "pizza"}};

void findKeys(int order, string s, vector<string> value) {
    if (order == 4) {
        keys.push_back(s);
        return;
    }
    if (value[order] != "-") {
        findKeys(order + 1, s + value[order], value);
        return;
    }
    for (auto t: types[order]) {
        findKeys(order + 1, s + t, value);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    // 1. info를 순회하면서 문자열 파싱 후에 모든 경우의 수 16(=2^4)가지에 점수를 넣는다.
    string an, a, b, c, d, e;
    for (auto i: info) {
        stringstream ss(i);
        ss >> a >> b >> c >> d >> e;
        scores[a+b+c+d].push_back(stoi(e));
    }
    // 2. 각 key에 대한 value들, 즉 점수들을 정렬한다.
    for (auto [key, scs]: scores) {
        sort(scores[key].begin(), scores[key].end());
    }
    // 3. 
    vector<int> ans;
    for (auto q: query) {
        stringstream ss(q);
        ss >> a >> an >> b >> an >> c >> an >> d >> e;
        keys.clear();
        findKeys(0, "", {a, b, c, d});
        int cnt = 0;
        for (auto key: keys) {
//            cnt += findBiggerThan(key, stoi(e)); O(N)의 방식임.
            int idx = lower_bound(scores[key].begin(), scores[key].end(), stoi(e)) - scores[key].begin();
            cnt += scores[key].size() - idx;
        }
        ans.push_back(cnt);
    }
    return ans;
}

/*
int findBiggerThan(string k, int s) { // O(N) -> 이분탐색, O(lgN) 시간 줄여야함.
    int i, n = scores[k].size();
    for (i = 0; i < n; i++) {
        if (s <= scores[k][i]) {
            break;
        }
    }
    return scores[k].size() - i;
}
 */