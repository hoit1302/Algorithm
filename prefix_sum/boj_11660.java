package prefix_sum;

import java.io.*;
import java.util.*;

public class boj_11660 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] arr = new int[N+1][N+1];
		for (int i = 1; i <= N; i++){
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N ; j++){
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		long[][] prefixSum = new long[N + 1][N + 1];
		Arrays.fill(prefixSum[0], 0);
		for (int i = 0; i <= N; i++) prefixSum[i][0] = 0;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + arr[i][j];
			}
		}
		while (M-- > 0) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			long answer = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
			bw.write(answer + "\n");
		}
		bw.flush();
	}
}
