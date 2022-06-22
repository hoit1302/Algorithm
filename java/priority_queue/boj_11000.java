package priority_queue;

import java.io.*;
import java.util.*;

public class boj_11000_sol {
	static class Course implements Comparable<Course> {
		long S, E;

		public Course(long s, long e) {
			this.S = s;
			this.E = e;
		}

		public int compareTo(Course c) {
			if (this.S - c.S > 0) return 1;
			else if (this.S == c.S) {
				if (this.E - c.E > 0) return 1;
				else if (this.E == c.E) return 0;
				return -1;
			}
			else return -1;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		PriorityQueue<Long> pq = new PriorityQueue<>();
		ArrayList<Course> arr = new ArrayList<>();
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			arr.add(new Course(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken())));
		}
		Collections.sort(arr);

		// 알고리즘
		pq.add(arr.get(0).E);
		for (int i = 1; i < N; i++) {
			if (pq.peek() <= arr.get(i).S) {
				pq.poll();
			}
			pq.add(arr.get(i).E);
		}
		int result = pq.size();
		bw.write(result + "\n");
		bw.flush();
	}
}
