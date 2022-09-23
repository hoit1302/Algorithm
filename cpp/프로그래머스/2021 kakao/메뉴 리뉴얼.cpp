#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// ref: https://www.youtube.com/watch?v=FX9n1PFv2K4&t=744s
vector<string> solution(vector<string> orders, vector<int> course) {
    map<string, int> freq[11]; // 요리 개수[], 요리 종류string, 빈도수int
    for (auto order: orders) {
        sort(order.begin(), order.end());
        // 한 order의 모든 조합 구하기
        for (int i = 1; i < (1 << order.size()); i++) {
            string menu;
            for (int j = 0; j < order.size(); j++) {
                if (i & (1 << j))
                    menu += order[j];
            }

            freq[menu.size()][menu]++;
        }
    }

    vector<string> ans;
    for (int c: course) {
        int mxfreq = 0;
        for (auto cook: freq[c]) {
            mxfreq = max(mxfreq, cook.second);
        }
        if (mxfreq < 2) continue;
        for (auto cook: freq[c]) {
            if (mxfreq == cook.second) {
                ans.push_back(cook.first);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
