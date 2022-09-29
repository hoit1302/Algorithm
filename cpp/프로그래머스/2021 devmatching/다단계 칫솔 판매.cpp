#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> ref;
map<string, int> profit;

void addProfit(string s, int a) {
    a *= 100;
    while (s != "-" && a) {
        profit[s] += (a - a / 10);
        s = ref[s];
        a /= 10;
    }
}

/*
 * 풀이 시간: 31분, map을 활용할 때는 value에 맞게 변수명을 잘 지어야 안 헷갈린다.
 */
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size(), m = seller.size();
    for (int i = 0; i < n; i++) {
        ref[enroll[i]] = referral[i];
    }
    for (int i = 0; i < m; i++) {
        addProfit(seller[i], amount[i]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = profit[enroll[i]];
    }
    return ans;
}