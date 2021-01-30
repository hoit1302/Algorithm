package binary_search;

import java.io.*;
import java.util.*;

public class boj_3079 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		long M = Long.parseLong(st.nextToken());

		int[] immigrationCheckpoint = new int[N];
		long start = 1, end = 1, max = 1, min = (int) 1e18;
		for (int i = 0; i < N; i++) {
			immigrationCheckpoint[i] = Integer.parseInt(br.readLine());
			max = Math.max(immigrationCheckpoint[i], max);
			min = Math.min(immigrationCheckpoint[i], min);
		}
		start = min * Math.max(1, Math.floorDiv(M, N));
		end = max * (int) Math.ceil(M / (double) N);
		long result = end;
		while (start <= end) {
			long mid = (start + end) / 2;
			int tempCnt = 0;
			for (int i = 0; i < N; i++) {
				if (tempCnt >= M) break;
				if (mid < immigrationCheckpoint[i]) continue;
				tempCnt += mid / immigrationCheckpoint[i];
			}
			if (tempCnt < M)
				start = mid + 1;
			else {
				result = Math.min(mid, result);
				end = mid - 1;
			}
		}
		bw.write(result + "\n");
		bw.flush();
	}
}
