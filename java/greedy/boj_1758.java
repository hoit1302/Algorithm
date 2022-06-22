package greedy;

import java.io.*;
import java.util.*;

public class boj_1758 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] tips = new int[N];
		long ans = 0; // 자료형을 조심하자! 1e9 < 1e(5+5)
		for (int i = 0; i < N; i++) tips[i] = Integer.parseInt(br.readLine());

		Arrays.sort(tips);
		for (int i = N - 1; i >= 0; i--) { // 정렬 후 반대로 요소 접근, 내림차순의 효과
			int minus = (N - 1) - i;
			if (0 < tips[i] - minus) ans += tips[i] - minus; // 음수 아니면 더하기
		}
		System.out.println(ans);
	}
}
