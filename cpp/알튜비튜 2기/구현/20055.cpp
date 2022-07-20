#include <iostream>
#include <vector>

using namespace std;

/*
 * 컨베이어 벨트 위의 로봇 [#](https://www.acmicpc.net/problem/20055)
 *
 * 코테에서 낼만한 좋은 문제.
 * 회전 아이디어는 투 포인터를 두어 잘 구현했음.
 * 틀린 부분 1. 0과 n-1이 연결되는 자료 구조를 다루는 것이 핵심임.
 * end에서 start로 차례로 순회해야하는데
 * end = 2, start = 5 이런 경우에만 집중해서 항상 end += SIZE을 했음.
 * start = 0, end = 5일 땐 end 값이 배로 커져서 로직을 더 여러번 수행함.
 * -> 결과값만 찍어서 확인했는데 너무 보기 어려웠음.
 * 디버깅할 때 로직이 분명한 부분은 제외하고 세부적으로 for loop의 idx 값을 확인해보자
 *
 * 2. 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
 * 이 조건 문장에서 이동하려는 칸에 로봇이 없어야 한다는 조건을 빼먹었었다.
 * 금방 찾기는 했지만 한 번에 작성할 수 있도록 문제를 답지처럼 계속 읽자!
 */
vector<int> belt, robot;

int rotatePos(int a, int n) {
    return (a - 1 + (2 * n)) % (2 * n);
}

int calIdx(int a, int n) {
    return a % (2 * n);
}

int findZeroCnt(int n) {
    int cnt = 0;
    for (int i = 0; i < n * 2; i++) {
        if (belt[i] == 0) {
            cnt++;
        }
    }
    return cnt;
}

void print(int step, int s, int e, int n) {
    cout << step << ' ' << s << ' ' << e << '\n';
    if (n < s) {
        e += n * 2;
    }
    cout << "belt : ";
    for (int i = s; i <= e; i++) {
        cout << belt[calIdx(i, n)] << ' ';
    }
    cout << '\n';
    cout << "robot: ";
    for (int i = s; i <= e; i++) {
        cout << robot[calIdx(i, n)] << ' ';
    }
    cout << '\n';
}

int sol(int n, int k) {
    robot.assign(2 * n, 0);
    int s = 0, e = n - 1, step = 1;
    while (true) {
        // print(step, s, e, n);
        // 1. 회전 - 시작과 끝을 가리키는 포인터만 이동 == 벨트 회전 & 로본
        s = rotatePos(s, n);
        e = rotatePos(e, n);

        // 2-1. 내리는 위치에 있는 로봇 내리기
        if (robot[e]) {
            robot[e] = 0;
        }

        // end -> start 로봇 이동시키기
        int tmp_e = e;
        if (n < s) {
            tmp_e = e + 2 * n;
        }
        for (int i = tmp_e - 1; i > s; i--) {
            if (robot[calIdx(i, n)] && belt[calIdx(i + 1, n)] && !robot[calIdx(i + 1, n)]) {
                robot[calIdx(i, n)] = 0;
                robot[calIdx(i + 1, n)] = 1;
                belt[calIdx(i + 1, n)]--;
            }

            if (robot[e]) {
                robot[e] = 0;
            }
        }

        // 3. start에 로봇 올리기
        if (belt[s]) {
            robot[s] = 1;
            belt[s]--;
        }
        print(step, s, e, n);

        // 4. 내구도가 0인 칸의 개수가 K개 이상인지 확인하고 return 시키기 -> 종료 조건
        if (k <= findZeroCnt(n)) {
            return step;
        }
        step++;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    belt.assign(2 * n, 0);
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i];
    }
    cout << sol(n, k);
}