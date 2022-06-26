#include <iostream>

using namespace std;

int sudoku[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

bool fillSudoku(int fill) {
    if (fill == 81) {
        return true;
    }

    int r = fill / 9; //row 위치
    int c = fill % 9; //column 위치

    if (sudoku[r][c] != 0) {
        return fillSudoku(fill + 1);
    }
    for (int i = 1; i <= 9; i++) {
        if (!row[r][i] && !col[c][i] && !square[(r / 3) * 3 + (c / 3)][i]) {
            row[r][i] = col[c][i] = square[(r / 3) * 3 + (c / 3)][i] = true;
            sudoku[r][c] = i;

            if (fillSudoku(fill + 1)) {
                return true;
            }

            //리셋
            row[r][i] = col[c][i] = square[(r / 3) * 3 + (c / 3)][i] = false;
            sudoku[r][c] = 0;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //입력 받기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != 0) {
                //이미 채워진 숫자라면
                row[i][sudoku[i][j]] = col[j][sudoku[i][j]] = square[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
            }
        }
    }

    //문제 풀기
    fillSudoku(0);

    // 출력하기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}