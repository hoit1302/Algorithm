#include <iostream>
#include <queue>

using namespace std;


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, k;
    queue<int> josephus;
    vector<int> josephus_seq;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        josephus.push(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k - 1; j++) {
            int front = josephus.front();
            josephus.pop();
            josephus.push(front);
        }
        josephus_seq.push_back(josephus.front());
        josephus.pop();
    }

    string res = "<";
    for (int i = 0; i < n-1; i++)
        res += to_string(josephus_seq[i]) + ", ";
    res += to_string(josephus_seq[n-1]) + ">\n";
    cout << res << '\n';
    return 0;
}