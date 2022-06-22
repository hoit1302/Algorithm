package dfs_bfs;

import java.io.*;
import java.util.*;

public class boj_16953 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long A = Long.parseLong(st.nextToken());
		long B = Long.parseLong(st.nextToken());

		bw.write(Long.toString(bfs(A, B)));
		bw.flush();
	}

	private static long bfs(long start, long end) {
		Queue<Point> queue = new LinkedList<>();
		queue.add(new Point(start, 1));

		while (!queue.isEmpty()) {
			Point temp = queue.poll();
			if (temp.x * 2 == end || temp.x * 10 + 1 == end) return temp.y + 1;
			if (temp.x > end) continue;
			queue.add(new Point(temp.x * 2, temp.y + 1));
			queue.add(new Point(temp.x * 10 + 1, temp.y + 1));
		}
		return -1;
	}

	static class Point {
		long x, y;

		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}
	}
}

