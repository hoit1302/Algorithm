package prefix_sum;

import java.io.*;
import java.util.*;

public class boj_11659 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		long[] prefixSum = new long[N+1];
		prefixSum[0] = 0;
		for (int i = 1; i <= N; i++)
			prefixSum[i] = prefixSum[i-1]+Integer.parseInt(st.nextToken());
		while (M-- > 0) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			bw.write(prefixSum[b] - prefixSum[a-1] + "\n");
		}
		bw.flush();
	}
}
