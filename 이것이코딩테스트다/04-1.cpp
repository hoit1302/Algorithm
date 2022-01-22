#include <iostream>
#include <vector>
using namespace std;

// 2차원~ 등의 공간 이동 첫번째 템플릿 !!!
// 거의 암기하고 있어야 함.
int main() {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    char dir[4] = {'L', 'U', 'R', 'D'};

    freopen("../input.txt", "r", stdin);
    int N, x = 1, y = 1;
    string str;
    cin >> N;
    cin.ignore();
    getline(cin, str); // 버퍼를 비워준 다음에 한 라인을 입력받을 수 있음.
    for (char i : str) { // 공백도 처리됨.
        int nx, ny;
        for (int j = 0; j < 4; j++) { // idx로 루프 돌아야 접근이 쉬움.
            if (i == dir[j]) {
                nx = x + dx[j];
                ny = y + dy[j];
            }
        }
        if (nx < 1 || N < nx || ny < 1 || N < ny)
            continue;
        x = nx; y = ny;
    }
    cout << x << " " << y << "\n";
    return 0;
}
