package dp;

import java.io.*;

public class boj_1463 {
	static int[] dp;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(br.readLine());
		dp = new int[1000001];
		dp[1] = 0;
		dp[2] = dp[3] = 1;
		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 1] + 1;
			if (i % 3 == 0 && dp[i / 3]+1 < dp[i]) dp[i] = dp[i / 3] + 1;
			if (i % 2 == 0 && dp[i / 2] +1< dp[i]) dp[i] = dp[i / 2] + 1;
		}
		bw.write(String.valueOf(dp[N]));
		bw.flush();
	}
}
