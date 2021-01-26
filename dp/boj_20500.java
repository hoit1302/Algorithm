package dp;

import java.io.*;

public class boj_20500 {
	static final int MOD = 1000000007;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		long[] dp = new long[N + 3];
		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;
		for (int i = 4; i <= N; i++) {
			dp[i] = ((dp[i - 2] * 2 % MOD) + dp[i - 1]) % MOD;
		}
		System.out.println(dp[N]);
	}
}
