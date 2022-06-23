#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, p, res = 0;
    cin >> n >> p;
    vector<stack<int>> s(7);
    while (n--) {
        int gui_str, fret;
        cin >> gui_str >> fret;

        while (!s[gui_str].empty() && s[gui_str].top() > fret) {
            s[gui_str].pop();
            res++;
        }
        if (s[gui_str].empty() || s[gui_str].top() < fret) {
            s[gui_str].push(fret);
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}
