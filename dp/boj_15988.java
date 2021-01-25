package dp;

import java.io.*;

public class boj_15988 {
	static long[] dp;
	static final int MOD = 1000000009;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		dp = new long[1000001];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= 1000000; i++)
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;

		while (T-- > 0) {
			int N = Integer.parseInt(br.readLine());
			sb.append(dp[N]).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
	}
}