package priority_queue;

import java.io.*;
import java.util.PriorityQueue;

// 작은 수를 먼저 합쳐야 한다. 작은 수가 여러번 더해지는 것이 효율적
// 우선순위 큐에서 작은 숫자 2개를 꺼낸 뒤 더해 다시 넣는 방식으로 풀면 된다.
// queue가 비었을 때 poll()은 null을 반환하고, remove()는 예외를 발생시킨다.
// 이 문제는 N==1일 때 비교할 카드가 없으므로 (이미 정렬되어있음) 0을 출력해야하는 것이 함정이었다.
public class boj_1715 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		int N = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < N;i++)
			pq.add(Integer.parseInt(br.readLine()));
		
		if (N == 1) {
			System.out.println(0);
			return;
		}
		
		int res = 0;
		for (int i = 0; i < N-1 ;i++) {
			int n1 = pq.poll();
			int n2 = pq.poll();
			pq.add(n1 + n2);
			res += (n1 + n2);
		}

		System.out.println(res);
	}
}
