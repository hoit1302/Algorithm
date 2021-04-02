package string;

import java.util.*;

public class epper_16_7 {

	private static ArrayList<String> sol(String s) {
		ArrayList<String> result = new ArrayList<>();
		String temp;

		// 초기값 설정
		if (s.charAt(0) == s.charAt(1)) {
			result.add("");
			temp = "";
		} else {
			temp = String.valueOf(s.charAt(0));
		}

		boolean lastSame = false;
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i - 1) == s.charAt(i)) {
				if (lastSame) continue;
				if (temp.length() > 2)
					result.add((String) temp.subSequence(0, temp.length() - 1));
				temp = "";
				lastSame = true;
			} else {
				lastSame = false;
				temp += s.charAt(i);
			}
		}
		result.add(temp);
		return result;
	}

	public static void main(String[] args) {
		String s1 = "pizza";
		System.out.println(sol(s1));
		String s2 = "mississippi";
		System.out.println(sol(s2));
		String s3 = "aabcddddefggg";
		System.out.println(sol(s3));
		String s4 = "abyyy";
		System.out.println(sol(s4));
		String s5 = "kkkkkk";
		System.out.println(sol(s5));
		String s6 = "abcaabbxyz";
		System.out.println(sol(s6));
		String s7 = "qwaabbbccccqw";
		System.out.println(sol(s7));
	}
}
