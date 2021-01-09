package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1080 {
    static int[][] A;
    static int[][] B;

    public static void change(int a, int b) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                A[i + a][j + b] = (A[i + a][j + b] == 0) ? 1 : 0;
        }
    }

    public static void main(String[] args) throws IOException {
        // 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        A = new int[N][M];
        B = new int[N][M];
        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            for (int j = 0; j < M; j++)
                A[i][j] = Integer.parseInt(String.valueOf(s.charAt(j)));
        }
        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            for (int j = 0; j < M; j++)
                B[i][j] = Integer.parseInt(String.valueOf(s.charAt(j)));
        }

        // 알고리즘
        int cnt = 0;
        for (int i = 0; i <= N - 3; i++) {
            for (int j = 0; j <= M - 3; j++) {
                if (A[i][j] != B[i][j]) { change(i, j); cnt++; }
            }
        }

        // 확인
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] != B[i][j]) {
                    System.out.println(-1);
                    return;
                }
            }
        }
        System.out.println(cnt);
    }
}

