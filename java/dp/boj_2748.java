package dp;

import java.io.*;
import java.util.*;

public class boj_2748 {
	static long[] dp;
	static int N;
	static long fibonacci(int n){
		if (dp[n] != -1) return dp[n];
		return dp[n] = fibonacci(n-1) + fibonacci(n-2);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		dp = new long[91];
		Arrays.fill(dp, -1); // 초기화
		// 초기값 설정
		dp[0] = 0;
		dp[1] = 1;
		System.out.println(fibonacci(N));
	}
}
