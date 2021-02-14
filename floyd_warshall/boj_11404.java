package floyd_warshall;

import java.io.*;
import java.util.*;

public class boj_11404 {

	static final int INF = (int) 1e9;
	static int[][] d;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder("");
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		d = new int[N + 1][N + 1];

		// 모든 칸 INF로 초기화
		for (int i = 1; i <= N; i++) Arrays.fill(d[i], INF);
		// 입력
		for (int k = 0; k < M; k++) {
			st = new StringTokenizer(br.readLine());
			int i = Integer.parseInt(st.nextToken());
			int j = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			// 처음이 아니라면
			if (d[i][j] != INF) d[i][j] = Math.min(a, d[i][j]);
			else d[i][j] = a;
		}

		// 알고리즘
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i == j)
						d[i][j] = 0;
					else if (d[i][k] + d[k][j] < d[i][j])
						d[i][j] = d[i][k] + d[k][j];
				}
			}
		}

		// 출력
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][j] == INF) sb.append("0 ");
				else sb.append(d[i][j]).append(" ");
			}
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
	}
}
