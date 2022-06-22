#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int sumNum(string str) {
    int num = 0;
    for (char i : str) {
        if (isdigit(i))
            num += i - '0';
    }
    return num;
}
bool cmpStr(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();

    int a_num = sumNum(a), b_num = sumNum(b);
//    cout << a_num << " ? " << b_num << '\n';
    if (a_num != b_num) {
        return a_num < b_num;
    }

    return a < b;
}

int main() {
    int n;
    vector<string> nums;

    cin >> n;
    nums.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), cmpStr);
    for (string str : nums)
        cout << str << '\n';
    return 0;
}
