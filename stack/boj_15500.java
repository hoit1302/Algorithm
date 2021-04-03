package stack;

import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class boj_15500 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		Stack<Integer> stack1 = new Stack<>();
		Stack<Integer> stack2 = new Stack<>();
		Stack<Integer> stack3 = new Stack<>();
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			stack1.push(Integer.parseInt(st.nextToken()));

		int cnt = 0;
		int n = N;
		while (stack3.size() != N) {
			if (stack1.empty()) { // 1 빔
				while (!stack2.empty()) {
					int pop2 = stack2.pop();
					if (pop2 == n) {
						stack3.push(pop2);
						sb.append("2 3\n");
						n--;
					} else {
						stack1.push(pop2);
						sb.append("2 1\n");
					} cnt++;
				}
			} else { // 2 빔, 2로 옮김
				while (!stack1.empty()) {
					int pop1 = stack1.pop();
					if (pop1 == n) {
						stack3.push(pop1);
						sb.append("1 3\n");
						n--;
					} else {
						stack2.push(pop1);
						sb.append("1 2\n");
					} cnt++;
				}
			}
		}
		bw.write(cnt + "\n");
		bw.write(sb.toString());
		bw.flush();
	}
}
