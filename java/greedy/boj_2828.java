package greedy;

import java.io.*;
import java.util.*;

// 바구니 시작점: basket
// 바구니 끝점: basket + M - 1

public class boj_2828 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int J = Integer.parseInt(br.readLine());
		int basket = 1, ans = 0;

		for (int i = 0; i < J; i++) {
			int position = Integer.parseInt(br.readLine());
			if (!(basket <= position && position <= basket + M - 1)) { // 현재 바구니 사이에 없으면
				int tempAns = Math.min(Math.abs(position - basket), Math.abs(position - (basket + M - 1)));
				ans += tempAns; // 최솟값 계산 후 정답값에 더해주기
				if (position < basket) basket -= tempAns; // 바구니를 왼쪽으로
				else basket += tempAns; // 바구니를 오른쪽으로 이동
			}
		}

		System.out.println(ans);
	}
}
