package greedy;

import java.io.*;
import java.util.*;

// 에러 종류는 2가지임.
// 1. '}' 가 등장하면 pop 해야하는데 없을 때.
// 헤결법: '{'로 바꿔서 push 해주고 문자를 바꿨으므로 cnt++
// 2. 모든 문자열을 체크한 뒤 '{'가 남아있는 경우.
// 해결법: 무조건 짝수개로 '{'가 남아있으므로, 스택의 요소 개수/2를 cnt에 더해줌

public class boj_4889 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Stack<Character> stack;
		StringBuilder sb = new StringBuilder();
		int i = 1, cnt;
		while (true) {
			String temp = br.readLine();
			if (temp.charAt(0) == '-') break;

			sb.append(i++).append(". ");
			cnt = 0;
			stack = new Stack<>();
			for (Character ch : temp.toCharArray()) {
				if (ch == '{') {
					stack.push('{');
				} else { // '}'
					if (stack.isEmpty()) {
						cnt++;
						stack.push('{');
					} else {
						stack.pop();
					}
				}
			}
			if (!stack.isEmpty())
				cnt += (stack.size() / 2);
			sb.append(cnt).append("\n");
		}

		System.out.println(sb);
	}
}
