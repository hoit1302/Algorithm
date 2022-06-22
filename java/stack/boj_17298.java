package stack;

//idea: 그 숫자의 오큰수에 해당하는 수를 구하는 것이 아닌 그 숫자가 어떤 수의 오큰수의 해당하는가?
import java.io.*;
import java.util.*;

public class boj_17298 {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		String[] temp = br.readLine().split(" ");
		int[] arr = new int[N];
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(temp[i]);

		Stack<Integer> st = new Stack<>();
		int[] res = new int[N];

		for (int i = 0; i < N; i++) {
			while (!st.empty() && arr[st.peek()] < arr[i]) {
				res[st.peek()] = arr[i];
				st.pop();
			}
			st.push(i);
		}
		
		while (!st.empty())
			res[st.pop()] = -1;

		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for (int i = 0; i < N; i++)
			bw.write(res[i] + " ");
		
		bw.flush();
	}
}
