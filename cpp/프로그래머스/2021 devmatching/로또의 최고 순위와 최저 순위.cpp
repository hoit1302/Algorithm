#include <vector>

using namespace std;

/*
 * 풀이시간: 9분 19초. 핵쉬움.
 */
int calRank(int match_cnt) {
    if (match_cnt <= 1) {
        return 6;
    } return 7 - match_cnt;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int match_cnt = 0;
    for (auto l: lottos) {
        for (auto w: win_nums) {
            if (l == w) {
                match_cnt++;
                break;
            }
        }
    }
    int zcnt = 0;
    for (auto l: lottos) {
        if (l == 0)
            zcnt++;
    }
    return {calRank(zcnt + match_cnt), calRank(match_cnt)};
}