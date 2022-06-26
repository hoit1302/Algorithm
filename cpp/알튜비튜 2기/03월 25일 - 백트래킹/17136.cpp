#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MAX = 5;
const int SIZE = 10;
const int INF = 26;
int res = INF;
vector<int> cnt(6, 0);
vector<vector<int>> paper(SIZE, vector<int>(SIZE));

void paint(int pos, int size, int color) {
    int r = pos / SIZE, c = pos % SIZE;
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            paper[i][j] = color;
        }
    }
    if (!color) cnt[size]++;
    else cnt[size]--;
}

// 해당 좌표가 유망한지 체크하는 promising() 함수
bool promising(int pos, int size) {
    int r = pos / SIZE, c = pos % SIZE;
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (!paper[i][j]) return false;
        }
    }
    return true;
}

void go(int pos) {
    // 가지치기, 한 종류를 5개 이상 사용했을 때, 기존 정답이 더 작을 때 return
    int tmp_res = accumulate(cnt.begin(), cnt.end(), 0);
    if (res < tmp_res)
        return;
    for (int i = 1; i <= MAX; i++) {
        if (5 < cnt[i]) {
            return;
        }
    }
    // 기저조건
    if (pos == SIZE * SIZE) {
        res = min(res, tmp_res);
        return;
    }

    // 호출하기, 경우 2가지, 0인 경우, 1인 경우
    int r = pos / SIZE, c = pos % SIZE;
    if (!paper[r][c]) {
        return go(pos + 1);
    }
    // 1이면, 색칠할 수 있는 사각형 크기를 찾아
    for (int i = 5; i >= 1; i--) {
        if (SIZE < r + i || SIZE < c + i) continue;
        if (promising(pos, i)) {
            // cout << "1인 좌표: " << r << ' ' << c << '\n';
            // cout << "시험해볼 사각형 크기: " << i << '\n';
            paint(pos, i, 0); // 2. 0으로 덮고
            go(pos + 1); // 3. 다음 사각형 찾기 호출
            paint(pos, i, 1); // 4. 1로 다시 떼네기
        }
    }

}

int main() {
    bool isExist1 = false;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> paper[i][j];
            if (paper[i][j]) {
                isExist1 = true;
            }
        }
    }
    go(0);
    if (!isExist1)
        cout << "0\n";
    else if (res == INF)
        cout << "-1\n";
    else
        cout << res << '\n';
}