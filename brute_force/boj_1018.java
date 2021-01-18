package brute_force;

import java.io.*;
import java.util.*;

public class boj_1018 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] chess = new char[n][m];
        for (int i = 0; i < n; i++)
            chess[i] = br.readLine().toCharArray();

        /* 알고리즘 */
        int min = 64;
        for (int i = 0; i <= n - 8; i++) {
            for (int j = 0; j <= m - 8; j++) {
                int temp = 0;

                /* white로 시작할 경우 계산 */
                for (int u = 0 ; u < 8; u++) {
                    for (int v = 0 ; v < 8 ; v++) {
                        if ((u +v) % 2 == 0) {
                            if (chess[i+u][j+v] == 'B')
                                temp++;
                        }
                        else {
                            if (chess[i+u][j+v] == 'W')
                                temp++;
                        }
                    }
                }
                temp = Math.min(temp, 64 - temp); // black시작과 white 시작 중 작은 거 선택
                min = Math.min(temp, min); // 변경사항 저장
            }
        }
        System.out.println(min);
    }
}
