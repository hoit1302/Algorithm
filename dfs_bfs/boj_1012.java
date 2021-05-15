package dfs_bfs;

import java.io.*;
import java.util.*;

public class boj_1012 {
	private static int M, N;
	private static int[][] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken()); // 가로길이 col 2번째
			N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			arr = new int[N][M];
			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				arr[y][x] = 1;
			}

			int res = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (arr[i][j] == 1) {
						arr[i][j] = 0; // 먼저 0 처리
						res++;
						dfs(i, j); // 주변 칸 탐색
					}
				}
			}

			bw.write(res + "\n");
		}
		bw.flush();
	}

	private static void dfs(int i, int j) {
		if (0 <= i - 1 && arr[i - 1][j] == 1) { // 위가 있는 경우에만
			arr[i - 1][j] = 0;
			dfs(i - 1, j); // 주변 칸 탐색
		}
		if (i + 1 < N && arr[i + 1][j] == 1) { // 아래가 있는 경우에만
			arr[i + 1][j] = 0;
			dfs(i + 1, j);
		}
		if (0 <= j - 1 && arr[i][j - 1] == 1) {// 왼쪽이 있는 경우에만
			arr[i][j - 1] = 0;
			dfs(i, j - 1);

		}
		if (j + 1 < M && arr[i][j + 1] == 1) { // 오른쪽이 있는 경우에만
			arr[i][j + 1] = 0;
			dfs(i, j + 1);
		}
	}
}
