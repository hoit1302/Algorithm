import java.io.*;
import java.util.*;

public class boj_1253 {
	private static int[] arr;
	private static int answer = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		arr = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);

		for (int i = 0; i < N; i++) {
			int temp = arr[i];
			int start = 0;
			int end = N - 1;
			boolean flag = false;

			while (start < end) {
				if (start == i) {
					start++;
					continue;
				}
				if (end == i) {
					end--;
					continue;
				}
				int sum = arr[start] + arr[end];

				if (sum > temp) {
					end = lowerBound(arr[end], start, end) - 1;
				} else if (sum < temp) {
					start = upperBound(arr[start], start, end);
				} else {
					flag = true;
					break;
				}
			}
			if (flag) answer++;
		}
		System.out.println(answer);
	}

	private static int upperBound(int target, int s, int e) {
		while (s < e) {
			int mid = (s + e) / 2;
			if (arr[mid] <= target) s = mid + 1;
			else e = mid;
		}
		return e;
	}

	private static int lowerBound(int target, int s, int e) {
		while (s < e) {
			int mid = (s + e) / 2;
			if (arr[mid] >= target) e = mid;
			else s = mid + 1;
		}
		return e;
	}
}