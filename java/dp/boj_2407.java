package dp;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class boj_2407 {

	public static BigInteger[][] dp;

	public static void setDpCombination(int n) {
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= i; j++)
				if (j == 0 || j == i) dp[i][j] = new BigInteger("1");
				else dp[i][j] = dp[i - 1][j - 1].add(dp[i - 1][j]);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		dp = new BigInteger[101][101];
		setDpCombination(N);
		System.out.println(dp[N][M]);
	}
}
