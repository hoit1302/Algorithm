package binary_search;

import java.io.*;
import java.util.*;

public class boj_2343 {
	private static int N, M;
	private static int[] lessons;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		lessons = new int[N];
		int start = 0, end = 0, result = 0;
		// 입력받으면서 end: 모든 레슨 길이의 합, start: 가장 긴 레슨 으로 초기화
		for (int i = 0; i < N; i++) {
			lessons[i] = Integer.parseInt(st.nextToken());
			end += lessons[i];
			start = Math.max(start, lessons[i]);
		}

		while (start <= end) {
			int mid = (start + end) / 2; // 블루레이의 길이
			if (blueRayNum(mid)) {
				result = mid;
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
		System.out.println(result);
	}

	// 나뉜 그룹의 개수가 M과 같거나 작을 경우 = (true 반환) -> { blueRay의 길이가 알맞거나 긴 경우로, end 감소시키기 }
	// 나뉜 그룹의 개수가 M보다 큰 경우 = (false 반환) -> { blueRay의 길이가 짧은 경우로, start 증가시키기 }
	private static boolean blueRayNum(int length) {
		int result = 0, tempCnt = 0;
		for (int i = 0; i < N; i++) {
			if (length < tempCnt + lessons[i]) { // 새로운 그룹으로 끊기
				result++;
				tempCnt = lessons[i];
			} else { // 같은 그룹에 이어서 담기
				tempCnt += lessons[i];
			}
		}
		return result < M;
	}
}
