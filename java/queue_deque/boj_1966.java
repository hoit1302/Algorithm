package queue_deque;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_1966 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		while (T-- > 0) {

			String[] s = br.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int M = Integer.parseInt(s[1]);
			Queue<Integer> idx = new LinkedList<>();
			Queue<Integer> nums = new LinkedList<>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			int i = 0;
			while (st.hasMoreTokens()) {
				idx.add(i++);
				int num = Integer.parseInt(st.nextToken());
				nums.add(num);
			}

			int res = 1;
			while (true) {
				int temp = nums.peek();
				boolean isMax = true;
				for (int j = 1; j < nums.size(); j++) {
					// 중요도 비교
					if (temp < ((LinkedList<Integer>) nums).get(j)) {
						isMax = false;
						break;
					}

				}

				// 해당하는 요소가 가장 큰 중요도 일 때
				if (isMax) {
					nums.remove();
					int ix = idx.remove();
					if (ix == M) {
						System.out.println(res);
						break;
					}
					res++;
				} else { // 해당 요소보다 큰 중요도가 있을 때 다음으로 넘김
					nums.add(nums.remove());
					idx.add(idx.remove());
				}

			}

		}
	}
}
