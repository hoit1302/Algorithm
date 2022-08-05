#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * 나무 재테크 [#](https://www.acmicpc.net/problem/16235)
 *
 * 걸린 시간: 2시간
 * - 현재 계산한 값이 현재 값에 영향을 주면 안됨.
 *   -> (봄에 나이가 증가하면서 죽은 나무가 양분이 되는 여름 연산을 연달아 하기 쉬움. 하지만 죽은 나무를 따로 저장해둔 뒤 봄이 끝나면 여름 작업이 시작되어야 함.)
 * - 1씩 증가하거나 삭제되고 나서 1이 삽입되는 특정한 상황.
 *   -> deque을 사용하여 앞뒤 삽입 삭제가 자유롭게,
 *   -> 정렬을 매번하지 않도록 구현 가능.
 *     원소 개수만큼 도는데 앞에서 빼고(삭제) 필요하면 수정해 뒤로 넣기(증가)
 *     가장 삽입될 수 있는 가장 작은 값인 1은 push_front()를 활용해서 넣어주면 됨.
 */
typedef pair<int, int> ci;
int land[10][10]; // 양분 현황
int a[10][10]; // 추가양분

struct tree {
    int age, x, y;
};

int cmp(const tree &aa, const tree &bb) {
    if (aa.age != bb.age) {
        return aa.age < bb.age;
    }
    return aa.x < bb.x;
}
deque<tree> trees;

void fall(int n, vector<ci> &breeding_trees) {
    int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

    for (auto[x, y] : breeding_trees) {
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || n <= nx || n <= ny) {
                continue;
            }
            trees.push_front({1, nx, ny});
        }
    }
}
void winter(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            land[i][j] += a[i][j];
        }
    }
}
void summer(vector<tree> &dead_tree) {
    for (tree t : dead_tree) {
        land[t.x][t.y] += (t.age / 2);
    }
}

int simul(int k, int n) {
    sort(trees.begin(), trees.end(), cmp);

    while (k--) {
        size_t tree_cnt = trees.size();
        vector<tree> dead_trees;
        vector<ci> breeding_trees;
        while (tree_cnt--) {
            tree t = trees.front();
            trees.pop_front();
            if (land[t.x][t.y] < t.age) {
                dead_trees.push_back(t);
                continue;
            } // 봄, 양분 먹고 나이 증가
            land[t.x][t.y] -= t.age;
            t.age++;
            trees.push_back(t);
            if (t.age % 5 == 0) {
                breeding_trees.push_back({t.x, t.y});
            }
        }
        summer(dead_trees); // 여름, 죽은 나무는 양분이 됨.
        fall(n, breeding_trees); // 가을, 번식
        winter(n); // 겨울, 양분 추가
    }
    return (int) trees.size();
}

int main() {
    int n, m, k, x, y, z;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            land[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        trees.push_back({z, x - 1, y - 1});
    }
    cout << simul(k, n);
}