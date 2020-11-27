package dfs_bfs;

import java.io.*;
import java.util.*;

//https://onejunu.tistory.com/48

public class boj_9205 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			
			boolean ok = false;
			int n = Integer.parseInt(br.readLine()); 
			Point[] p = new Point[n+2];
			// 입력받기 점으로 묶어 저장
			for (int i = 0; i < n + 2; i++) {
				String[] temp = br.readLine().split(" ");
				p[i] = new Point(Integer.parseInt(temp[0]), Integer.parseInt(temp[1]));
			}
			p[n + 1].isDest = true;

			// 각 점 사이에 거리가 1000 이하이면 연결시키기.
			for (int i = 0; i < n + 1; i++) {
				for (int j = i + 1; j < n + 2; j++) {
					if (Math.abs(p[i].x - p[j].x) + Math.abs(p[i].y - p[j].y) <= 1000) {
						p[i].conn.add(p[j]);
						p[j].conn.add(p[i]);
					}
				}
			}

			// 탐색. bfs
			Deque<Point> q = new ArrayDeque<>();
			q.offer(p[0]); 	p[0].visited = true;

			while (!q.isEmpty()) {
				Point cur = q.pollFirst();
				if (cur.isDest) {
					ok = true;
					break;
				}

				for (Point pp : cur.conn) {
					if (pp.visited == false) {
						pp.visited = true; 	q.offer(pp);
					}
				}
			}

			System.out.println(ok ? "happy" : "sad");
		}
	}

	static class Point {
		int x, y;
		boolean visited = false;
		boolean isDest = false;
		ArrayList<Point> conn = new ArrayList<>();

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
