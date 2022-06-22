package stack;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class boj_10828 {
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Stack<Integer> st = new Stack<>();
		int N = Integer.parseInt(br.readLine());
		
		while (N > 0) {
			N--;
			
			String s = br.readLine();
			if (s.equals("pop")) {
				System.out.println(st.empty() ? "-1" : st.pop());
			} else if (s.equals("size")) {
				System.out.println(st.size());
			} else if (s.equals("empty")){
				System.out.println(st.empty() ? "1" : "0");
			} else if (s.equals("top")) {
				System.out.println(st.empty()? "-1" : st.peek());
			} else {
				st.push(Integer.parseInt(s.split(" ")[1]));
			}
		}
	}
}
