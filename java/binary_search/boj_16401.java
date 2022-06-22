package binary_search;

import java.io.*;
import java.util.*;

public class boj_16401 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] snacks = new int[N];
		int start = 1, end = 1;
		for (int i = 0; i < N; i++) {
			snacks[i] = Integer.parseInt(st.nextToken());
			end = Math.max(end, snacks[i]);
		}

		int result = 0;
		while (start <= end) {
			int mid = (start + end) / 2;
			int tempCnt = 0;
			for (int i = 0; i < N; i++) {
				if (tempCnt >= M) break;
				if (mid <= snacks[i]) tempCnt += (snacks[i]/mid);
			}
			if (tempCnt < M)
				end = mid - 1;
			else {
				result = Math.max(result, mid);
				start = mid + 1;
			}
		}
		bw.write(result+"\n");
		bw.flush();
	}
}
