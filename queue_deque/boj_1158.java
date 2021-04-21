package queue_deque;

import java.io.*;
import java.util.*;

public class boj_1158 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		Queue<Integer> q = new LinkedList<>();
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= n; i++) q.offer(i);
		int cnt = 0;
		sb.append("<");
		while (!q.isEmpty()) {
			int a = q.peek();
			q.poll();
			cnt++;
			if (cnt == k) {
				if (q.size() == 0) sb.append(a).append(">");
				else sb.append(a).append(", ");
				cnt = 0;
			} else q.offer(a);
		}
		bw.write(String.valueOf(sb));
		bw.flush();
	}
}