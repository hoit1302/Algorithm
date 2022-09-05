#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e18;

ll getDist(pi start, pi end) {
    return abs(start.first - end.first) + abs(start.second - end.second);
}

int main()
{
    int n;
    cin >> n;
    pi start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    pi answer = { 0, INF };
    for (int i = 0; i < n; i++) {
        int m;
        vector<pi> middle;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int s, e;
            cin >> s >> e;
            middle.push_back({ s, e });
        }
        long long dist = getDist(start, middle[0]);
        for (int j = 0; j < middle.size() - 1; j++) {
            dist += getDist(middle[j], middle[j + 1]);
        }
        dist += getDist(middle[middle.size() - 1], end);

        if (answer.second > dist) {
            answer.first = i + 1;
            answer.second = dist;
        }
    }
    cout << answer.first;
}
