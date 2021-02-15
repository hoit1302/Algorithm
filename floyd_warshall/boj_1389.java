package floyd_warshall;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_1389 {
	private static final int INF = (int) 1e9;
	private static int[][] Graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		// 그래프 입력
		Graph = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) Arrays.fill(Graph[i], INF);
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			Graph[a][b] = 1;
			Graph[b][a] = 1;
		}

		for (int k = 1; k <= N; k++) { // 거쳐감
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					Graph[i][j] =
						Math.min(Graph[i][k] + Graph[k][j], Graph[i][j]);
				}
			}
		}
		int result = 1, resultMin = INF;
		for (int i = 1; i <= N; i++) {
			int tempSum = 0;
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				tempSum += Graph[i][j];
			}
			if (tempSum < resultMin) {
				resultMin = tempSum;
				result = i;
			}
		}
		bw.write(result + "\n");
		bw.flush();
	}
}
