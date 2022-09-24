#include <string>
#include <vector>

using namespace std;
typedef long long ll;
vector<int> s;
int findProperLen (int bsz) {
    for (int i = 0; i < s.size(); i++) {
        if (bsz <= s[i]) {
            return s[i];
        }
    }
}
bool isAll0(string str) {
    for (char ch: str) {
        if (ch != '0') return false;
    } return true;
}
string to2(ll n) {
    if (n < 2) return to_string(n);
    return to2(n / 2) + to_string(n % 2);
}

bool btree(string tree) {
    if (tree.size() == 1) {
        return true;
    }
    int hpos = tree.size() / 2;
//    cout << "문자열: " << tree << ", 중간위치: " << hpos << '\n';
    string pre = tree.substr(0, hpos), post = tree.substr(hpos + 1);
    if (tree[hpos] == '1') {
        if (!btree(pre) || !btree(post))
            return false;
        return true;
    }
    if (!isAll0(pre) || !isAll0(post)) {
        return false;
    }
    return true;
}

vector<int> solution(vector<ll> numbers) {
    s.push_back(1);
    int j = 2;
    for (int i = 1; i < 10; i++) {
        s.push_back(s[i - 1] + j);
        j *= 2;
    }
    vector<int> ans;
    for (ll num: numbers) {
        string b = to2(num);
        int len = findProperLen(b.size());
        string bi;
        for (int i = 0; i < len - b.size(); i++) {
            bi.append(1, '0');
        } bi.append(b);
        ans.push_back(btree(bi));
    }
    return ans;
}