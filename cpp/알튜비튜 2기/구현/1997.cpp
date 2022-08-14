#include <iostream>
#include <vector>

using namespace std;
typedef vector<string> block;
vector<string> box;

bool isStackPos(int pos, block &bl, int w) {
    for (int i = 0; i < bl.size(); i++) {
        for (int j = 0; j < w; j++) {
            if (bl[i][j] == 'X' && box[pos + i][j] == 'X') {
                return false;
            }
        }
    } return true;
}
int promising(block &bl, int b, int w) {
    for (int i = 0; i < b; i++) {
        if (b < i + bl.size()) {
            return -1; // 쌓을 수 없는 경우
        }
        // i번째 열에 넣을 수 있냐
        if (isStackPos(i, bl, w)) {
            return i; // 쌓을 수 있는 경우
        }
    } return -1;
}
void stack(int pos, block &bl, int w) {
    for (int i = 0; i < bl.size(); i++) {
        for (int j = 0; j < w; j++) {
            if (bl[i][j] == 'X') {
                box[pos + i][j] = 'X';
            }
        }
    }
}
int getHeight(int b, int w) {
    int res = -1;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < w; j++) {
            if (box[i][j] == 'X') {
                res = max(res, i);
                break;
            }
        }
    }
    return res;
}

/*
 * 박스포장 [#](https://www.acmicpc.net/problem/1997)
 * 테트리스처럼 블럭을 제한된 높이 내에서 쌓는 문제. 풀어냈고 아이디어만 가져가기
 * 대부분 2차원 배열을 다룰 때 아래 방향으로 흘러가도록 구현한다.
 * 입력받을 때 x축 대칭시키고 다루자.
 */
int main() {
    int n, w, b, h;
    cin >> n >> w >> b;
    string str(w, '.');
    vector<int> ans;
    box.assign(b, str); // 초기화
    while (n--) {
        cin >> h;
        block bl(h);
        for (int i = h - 1; i >= 0; i--) {
            cin >> bl[i];
        }
        int res = promising(bl, b, w);
        if (res == -1) { // 다음 블럭에 쌓아야 함.
            ans.push_back(getHeight(b, w)); // 답 저장
            box.assign(b, str); // 초기화
            res = 0;
        }
        stack(res, bl, w);
    }
    ans.push_back(getHeight(b, w)); // 답 저장
    for (int a : ans) {
        cout << a + 1 << ' ';
    } cout << '\n';
}