package brute_force;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_9329 {
	static int[][] info;
	static int[] coupons;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			String[] temp = br.readLine().split(" ");
			int N = Integer.parseInt(temp[0]);
			int M = Integer.parseInt(temp[1]);

			/* 서로 다른 쿠폰의 정보 입력 받기 */
			info = new int[N][31];
			for (int i = 0; i < N; i++) {
				int j = 0;
				String[] strnums = br.readLine().split(" ");
				for (String s : strnums)
					info[i][j++] = Integer.parseInt(s);
			}

			/* 코치가 가지고 있는 쿠폰 개수 입력받기 */
			coupons = new int[M + 1];
			int a = 1;
			String[] strnums = br.readLine().split(" ");
			for (String s : strnums)
				coupons[a++] = Integer.parseInt(s);
			
			/* 계산 후 출력 */
			int ans = 0;
			for (int i = 0; i < N; i++) {
				int couponNum = info[i][0];
				int money = info[i][couponNum+1];
				int minNum = coupons[info[i][1]]; // 초기화 첫번째수
				for (int j = 1; j<= couponNum; j++)
					minNum = Math.min(minNum, coupons[info[i][j]]);
				ans += (minNum * money);
			}
			System.out.println(ans);
		}

	}
}
