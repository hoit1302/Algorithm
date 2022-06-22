package dfs_bfs;

import java.awt.*;
import java.io.*;
import java.util.*;

public class boj_1697 {
	private static int[] check;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		bw.write(Integer.toString(bfs(N, K) - 1));
		bw.flush();
	}

	private static Integer bfs(int start, int end) {
		Queue<Integer> queue = new LinkedList<>();
		check = new int[(int) 2e6 + 1];
		queue.add(start);
		check[start] = 1;

		while (!queue.isEmpty()) {
			int temp = queue.poll();
			if (temp == end) return check[end];
			if (temp > (int) 1e6) continue;
			if (0 <= temp - 1) {
				if (check[temp - 1] == 0) {
					queue.add(temp - 1);
					check[temp - 1] = check[temp] + 1;
				}
			}
			if (temp + 1 < 2e6 + 1) {
				if (check[temp + 1] == 0) {
					queue.add(temp + 1);
					check[temp + 1] = check[temp] + 1;
				}
			}
			if (temp * 2 < 2e6 + 1) {
				if (check[temp * 2] == 0) {
					queue.add(temp * 2);
					check[temp * 2] = check[temp] + 1;
				}
			}
		}
		return -1;
	}
}
