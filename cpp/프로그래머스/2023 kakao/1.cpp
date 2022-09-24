#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string calValidDay(string day, int dur) {
    int y = stoi(day.substr(0, 4)), m = stoi(day.substr(5, 2)), d = stoi(day.substr(8));

    y += dur / 12;
    m += dur % 12;
    if (13 <= m) {
        m %= 12;
        y++;
    }
    d--;
    if (d == 0) {
        d = 28;
        m--;
        if (m == 0) {
            m = 12;
            y--;
        }
    }

    return to_string(y) + "." +
           (m < 10 ? "0": "") + to_string(m) + "." +
           (d < 10 ? "0": "") + to_string(d);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    string kind, dur, day;
    map<string, int> t_p;
    for (auto term: terms) {
        stringstream ss(term);
        ss >> kind >> dur;
        t_p[kind] = stoi(dur);
    }

    vector<int> ans;
    int i = 1;
    for (auto privacy: privacies) {
        stringstream ss(privacy);
        ss >> day >> kind;
        // cout << calValidDay(day, t_p[kind]) << ' ' << today << '\n';
        if (calValidDay(day, t_p[kind]) < today) {
            ans.push_back(i);
        } i++;
    }
    return ans;
}