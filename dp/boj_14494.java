package dp;

import java.io.*;
import java.util.*;

public class boj_14494 {
	private static final int MOD = 1000000007;
	private static int[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		dp = new int[N+1][M+1];

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (i == 1 || j == 1) dp[i][j] = 1;
				else {
					long temp = ((long)dp[i-1][j-1] + (long)dp[i][j-1] + (long)dp[i-1][j]) % MOD;
					dp[i][j] = (int)temp;
				}
			}
		}
		bw.write(Integer.toString(dp[N][M]));
		bw.flush();
	}
}
