package back_tracking;

import java.awt.*;
import java.io.*;
import java.util.*;

public class boj_2580 {
    private static int[][] sudoku;
    private static ArrayList<Point> zeros;

    private static boolean solve(int num) {
        if (num == zeros.size()) return true;
        int row = zeros.get(num).x;
        int col = zeros.get(num).y;
        for (int i = 1; i <= 9; i++) {
            if (check(row, col, i)) { // 스도쿠에 넣을 수 있음.
                sudoku[row][col] = i;
                if (solve(num + 1)) return true;
                else sudoku[row][col] = 0;
            }
        }
        return false;
    }

    private static boolean check(int row, int col, int checkNum) {
        // 1. 가로에 중복되는 숫자가 있는지 확인
        for (int i = 0; i < 9; i++)
            if (sudoku[row][i] == checkNum) return false;
        // 2. 세로에 중복되는 숫자가 있는지 확인
        for (int i = 0; i < 9; i++)
            if (sudoku[i][col] == checkNum) return false;
        // 3. 해당 좌표가 포함된 3*3 에 중복되는 숫자가 있는지 확인
        for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
            for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++) {
                if (sudoku[i][j] == checkNum) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        sudoku = new int[9][9];
        zeros = new ArrayList<>();
        // 입력
        // 1.한 줄씩 string으로 입력받음 2.내용을 공백으로 나누어 spring 배열이 됨 3.string[] ㅡ> int[] 변환
        // 입력 받다가 0인 좌표의 경우 zeros 리스트에 추가해줌.
        for (int i = 0; i < 9; i++) {
            sudoku[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < 9; j++) {
                if (sudoku[i][j] == 0) {
                    zeros.add(new Point(i, j));
                }
            }
        }
        solve(0);

        // 출력
        // 문자열로 모든 내용을 이어붙인 뒤 한 줄에 출력 (시간 절약)
        for (int i = 0; i < 9; i++) {
            for (int c : sudoku[i])
                sb.append(c).append(" ");
            sb.append("\n");
        }
        bw.write(String.valueOf(sb));
        bw.flush();
    }
}
