#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score, player;
vector<int> entry = {0, 1, 2, 3, 4, 5, 6, 7, 8}; //선수 순서
vector<vector<int>> board;

/**
 * 주자들 진루처리
 *
 * 0010 : 1루에 주자 존재
 * 0100 : 2루에 주자 존재
 * 1010 : 1, 3루에 주자 존재
 */
void running(int &run, int num) {
    run |= (1 << 0); // 0번 플레이트에 타자 표시
    for (int i = (4 - num); i < 4; i++) { //홈까지 진루할 수 있는 주자들
        if (run & (1 << i)) { //주자가 있다면
            run &= ~(1 << i); //주자가 홈인 했기 때문에 플레이트를 비워줌
            score++;
        }
    }
    run = run << num; //주자들 이동
}

//idx 이닝 플레이
void playGame(int idx) {
    int out = 0, run = 0;
    while (out != 3) {
        int hit = board[idx][entry[player]]; //이번 주자의 결과
        if (!hit) { // 아웃
            out++;
        }
        else { // 존재하는 모든 주자 진루
            running(run, hit);
        }
        player = (player + 1) % 9; //다음 선수
    }
}

/**
 * ⚾, [#](https://www.acmicpc.net/problem/17281)
 * 1시간 30분 문제 풀이 시도, 실패함. 해설 보고 공부함. 다시 구현해볼 문제.
 * 주어진 숫자가 굉장히 작을 땐 가장 먼저 브루트 포스를 의심해보자.
 *
 * 비트마스킹 주요 문법
 * run |= (1 << idx); // 원소 추가
 * if (run & (1 << i)) // 원소의 존재여부 확인
 * run &= ~(1 << i); // 원소 삭제
 */

int main() {
    int n, ans = 0;

    //입력
    cin >> n;
    board.assign(n, vector<int>(9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    do {
        swap(entry[0], entry[3]);
        score = player = 0;
        for (int i = 0; i < n; i++) {
            playGame(i);
        }
        ans = max(ans, score);
        swap(entry[3], entry[0]);
    } while (next_permutation(entry.begin() + 1, entry.end()));

    //출력
    cout << ans;
    return 0;
}
