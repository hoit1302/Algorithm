package priority_queue;

import java.io.*;
import java.util.*;

public class boj_11286 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());

		// 우선 순위 큐 선언.
		// 만약 o1과 o2의 절대 값이 같다면 실제 숫자를 기준으로 오름차순으로 정렬
		// 아니라면 절대값을 기준으로 오름차순으로 정렬
		PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) ->
			Math.abs(o1) == Math.abs(o2) ? (o1 - o2) : (Math.abs(o1) - Math.abs(o2))
		);

		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(br.readLine());
			if (num == 0) sb.append(pq.size() == 0 ? 0 : pq.poll()).append('\n');
			else pq.add(num);
		}
		bw.write(sb.toString());
		bw.flush();
	}
}
