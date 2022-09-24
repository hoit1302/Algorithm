#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

bool all0(vector<int> &des, vector<int> &pis) {
    for (int d: des) {
        if (d != 0)
            return false;
    }
    for (int p: pis) {
        if (p != 0)
            return false;
    }
    return true;
}

long long solution(int cap, int n, vector<int> des, vector<int> pis) {
    ll ans = 0;
    if (all0(des, pis)) return 0;

    int d_end = n - 1, p_end = n - 1;
    while (0 <= d_end || 0 <= p_end) {
        int d_cnt = 0, p_cnt = 0, dmx = d_end, pmx = p_end;
        // 1. d에 관해
        for (int i = d_end; i >= 0; i--) {
            if (d_cnt + des[i] <= cap) {
                d_cnt += des[i];
                des[i] = 0;
                d_end = i - 1;
            } else if (d_cnt < cap) {
                des[i] -= cap - d_cnt;
                d_end = i;
                break;
            } else {
                break;
            }
        }
        // 2. p에 관해
        for (int i = p_end; i >= 0; i--) {
            if (p_cnt + pis[i] <= cap) {
                p_cnt += pis[i];
                pis[i] = 0;
                p_end = i - 1;
            } else if (p_cnt < cap) {
                pis[i] -= cap - p_cnt;
                p_end = i;
                break;
            } else {
                break;
            }
        }
        ans += (max(dmx, pmx) + 1) * 2;
    }
    return ans;
}