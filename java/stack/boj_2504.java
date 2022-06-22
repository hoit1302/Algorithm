package stack;

import java.io.*;
import java.util.*;

public class boj_2504 {
	public static Stack<String> stack;
	public static int result = 0, len = 0;
	public static char[] bracket;

	public static boolean calc(int n, String bracket) {
		int tempResult = 0;
		while (true) {
			// stack이 empty인 경우 pop하면 런타임 에러를 뱉어내므로, 판별해준다.
			if (stack.empty()) return false;
			String peek = stack.peek();
			if (Character.isDigit(peek.charAt(0))) { // 숫자이면
				tempResult += Integer.parseInt(stack.pop());
			} else if (peek.equals(bracket)) { // "("일 경우, "("를 빼고 계산한 숫자를 push
				stack.pop();
				if (tempResult == 0) // 갱신된 숫자가 없는 경우, 2 또는 3을 바로 push
					stack.push(Integer.toString(n));
				else { // 갱신된 숫자가 있는 경우, 2 또는 3을 곱해서 push
					tempResult *= n;
					stack.push(Integer.toString(tempResult));
				}
				break;
			} else return false;
		}
		return true;
	}

	public static boolean go(int index) {
		if (index == len) {
			result += Integer.parseInt(stack.pop());
			return stack.empty();
		}

		if (bracket[index] == '(' || bracket[index] == '[') {
			if (!stack.empty())
				if (stack.size() == 1 && Character.isDigit(stack.peek().charAt(0)))
					result += Integer.parseInt(stack.pop());
			stack.push(Character.toString(bracket[index]));
			return go(index + 1);
		} else if (bracket[index] == ')') {
			if (!calc(2, "(")) return false;
			return go(index + 1);
		} else if (bracket[index] == ']') {
			if (!calc(3, "[")) return false;
			return go(index + 1);
		} else { // 이러한 입력은 주어지지 않으므로 위의 else if를 else로 바꿔 실행해도 AC 받지만, 코드 가독성을 위해 추가
			return false;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		bracket = br.readLine().toCharArray();
		len = bracket.length;
		stack = new Stack<>();
		if (go(0)) System.out.println(result);
		else System.out.println("0");
	}
}
