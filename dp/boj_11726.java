package dp;

import java.io.*;

public class boj_11726 {
	static final int MOD = 10007;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		long[] dp = new long[N + 3];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i <= N; i++)
			dp[i] = (dp[i - 1] + dp[i-2]) % MOD;
		System.out.println(dp[N]);
	}
}
