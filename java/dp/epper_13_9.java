package dp;

import java.io.*;
import java.util.*;

// boj_2156과 동일한 문제
class epper_13_9 {
	static int[] dp;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] money = new int[N + 1];
		for (int i = 1; i <= N; i++)
			money[i] = Integer.parseInt(st.nextToken());

		// i번째 길까지 갔을 때 최대 주울 수 있는 돈을 dp 배열에 memorization
		dp = new int[30001];
		dp[1] = money[1];
		dp[2] = money[1] + money[2];
		for (int i = 3; i <= N; i++) {
			dp[i] = Math.max(dp[i - 2], dp[i - 3] + money[i - 1]) + money[i]; // i번째를 선택했을 때의 최대값
			dp[i] = Math.max(dp[i - 1], dp[i]); // i번째를 선택하지 않는 경우와 한 번 더 비교
		}
		System.out.println(dp[N]);
	}
}
