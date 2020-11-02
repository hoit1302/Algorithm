package stack;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class boj_1935 {

	public static void main(String[] args) throws IOException{
		Stack<Double> st = new Stack<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String exp = br.readLine();
		double[] nums = new double[N];
		
		for (int i = 0 ; i < N; i++)
			nums[i] = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < exp.length(); i++) {
			char ch = exp.charAt(i);
			if (Character.isLetter(ch)) { // 영문(피연산자)이면
				st.push(nums[(int)ch - 65]);
			} else { // 연산자이면
				double n1 = st.pop();
				double n2 = st.pop();
				switch (ch) {
				case '+':
					st.push(n2+n1);
					break;
				case '-':
					st.push(n2-n1);
					break;
				case '*':
					st.push(n2*n1);
					break;
				case '/':
					st.push(n2/n1);
					break;
				}
			}
		}
		System.out.printf("%.2f\n", st.pop());
	}
}