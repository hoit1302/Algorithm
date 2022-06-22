package epper;

import java.io.*;
import java.util.*;

public class epper_상_1 {
	static long solution(int N, long[][] money) {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0)
					money[i][j] += money[i - 1][0];  // 가장 왼쪽
				else if (j == i)
					money[i][j] += money[i - 1][j - 1];  // 가장 오른쪽
				else
					money[i][j] += Math.max(money[i - 1][j - 1], money[i - 1][j]);  // 가운데
			}
		}
		// 맨 아래에 도착해야 하므로 맨 아랫줄의 값 중 가장 큰 합을 정답으로 반환한다.
		long ans = money[N - 1][0];
		for (int j = 0; j <= N - 1; j++)
			ans = Math.max(money[N - 1][j], ans);
		return ans;
	}


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		long[][] money = new long[N][];
		for (int i = 0 ; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			money[i] = new long[i+1];
			for (int j = 0; j <= i; j++)
				money[i][j] = Long.parseLong(st.nextToken());
		}
		System.out.println(solution(N, money));
	}
}
