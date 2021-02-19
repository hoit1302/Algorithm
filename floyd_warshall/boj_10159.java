package floyd_warshall;

import java.io.*;
import java.util.*;

public class boj_10159 {
	private static int[][] Graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		Graph = new int[N + 1][N + 1]; // 모든 칸 0으로 초기화
		// 입력
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			Graph[a][b] = 1;
		}

		// 알고리즘
		for (int k = 1; k <= N; k++) { // 거쳐감
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i == j) Graph[i][j] = 1;
					if (Graph[i][k] == 1 && Graph[k][j] == 1)
						Graph[i][j] = 1;
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (Graph[i][j] == 1) Graph[j][i] = 1;
			}
		}
		// 결과 출력
		for (int i = 1; i <= N; i++) {
			int tempResult = 0;
			for (int j = 1; j <= N; j++) {
				if (Graph[i][j] == 0)
					tempResult++;
			}
			bw.write(tempResult + "\n");
		}
		bw.flush();
	}
}
