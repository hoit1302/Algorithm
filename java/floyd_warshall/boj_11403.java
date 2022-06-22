package floyd_warshall;

import java.io.*;
import java.util.*;

public class boj_11403 {
	static int[][] Graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder("");
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());
		 Graph = new int[N + 1][N + 1]; // 모든 칸 0으로 초기화

		 // 입력
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++)
				Graph[i][j] = Integer.parseInt(st.nextToken());
		}

		// 알고리즘
		for (int k = 1; k <= N; k++) { // 거쳐감
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (Graph[i][k] == 1 && Graph[k][j] == 1)
						Graph[i][j] = 1;
				}
			}
		}

		// 출력
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				sb.append(Graph[i][j]).append(" ");
			}
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
	}
}
