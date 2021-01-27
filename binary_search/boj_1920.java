package binary_search;

import java.io.*;
import java.util.*;

public class boj_1920 {

	private static int[] nums;
	private static int N;

	private static boolean binarySearch(int temp) {
		int left = 0;
		int right = N-1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] < temp) left = mid + 1;
			else if (nums[mid] == temp) return true;
			else right = mid - 1;
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		nums = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) nums[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(nums);

		int M = Integer.parseInt(br.readLine());
		int[] checkNums = new int[M];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) checkNums[i] = Integer.parseInt(st.nextToken());
		for (int i = 0; i < M; i++) {
			if (binarySearch(checkNums[i])) sb.append("1\n");
			else sb.append("0\n");
		}
		bw.write(String.valueOf(sb));
		bw.flush();
	}
}
