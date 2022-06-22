#include <iostream>
#include <vector>
#include <algorithm>

#define name first
#define score second
using namespace std;

// p. 180: 성적이 낮은 순서로 학생 출력하기
bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.score < b.score;
}

int main() {
    freopen("../input.txt", "r", stdin);
    int N, s;
    string n;
    cin >> N;
    vector<pair<string, int> > v(N);
    for (int i = 0; i < N; i++) {
        cin >> n >> s;
        v[i] = {n, s};
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << v[i].name << " ";
    }
    cout << "\n";
    return 0;
}

