package prefix_sum;

import java.io.*;
import java.util.StringTokenizer;

public class boj_20002 {
	static int[][] prefixSum; // 전역변수 -> 0으로 자동 초기화

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int[][] field = new int[N + 1][N + 1];
		prefixSum = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				field[i][j] = Integer.parseInt(st.nextToken());
				prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + field[i][j];
			}
		}
		int cnt = 0;
		long result = prefixSum[1][1];
		for (int k = 1; k <= N; k++) { // 가로와 세로의 길이가 모두 K인 경우를 계산
			for (int i = 0; i + k <= N; i++) {
				for (int j = 0; j + k <= N; j++) {
					int value = prefixSum[i + k][j + k] - prefixSum[i + k][j] - prefixSum[i][j + k] + prefixSum[i][j];
					result = Math.max(result, value);
					cnt++;
				}
			}
		}
		bw.write(result + "\n");
		bw.flush();
	}
}
