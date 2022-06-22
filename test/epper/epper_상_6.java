package epper;

import java.util.*;

class Solution {

	static HashSet<String> dfs(int b, boolean[] visited, HashSet<String> s, String[] user_id, String[] banned_id) {
		if (b == banned_id.length) {
			StringBuilder str = new StringBuilder();
			for (int i = 0; i < user_id.length; i++)
				if (visited[i]) str.append(i); // 문자열 조합 생성
			s.add(str.toString()); // 중복되지 않게 문자열 조합 저장합니다.
			return s;
		}

		for (int i = 0; i < user_id.length; i++) {
			if (visited[i]) continue; // 제재된 아이디 제외
			if (user_id[i].length() != banned_id[b].length())
				continue; // 문자열의 길이가 다르면 해당 제재 아이디와 관계 없으므로 제외합니다.
			boolean temp = true;
			for (int j = 0; j < user_id[i].length(); j++) {
				if ((user_id[i].charAt(j) == banned_id[b].charAt(j)) || (banned_id[b].charAt(j) == '*')) {
					continue;
				} else { // 한 문자라도 다르거나 ‘*’가 아닐 때
					temp = false;
					break;
				}
			}
			// 제재 사용자에 포함되는 아이디일 때
			if (temp) {
				visited[i] = true; // 응모자 아이디 사용 표시
				s = dfs(b + 1, visited, s, user_id, banned_id);
				visited[i] = false; // 응모자 아이디 사용 표시 해제
			}
		}
		return s;
	}

	public static int solution(String[] user_id, String[] banned_id) {
		int answer = 0; // 문자열 조합을 저장할 집합
		HashSet<String> s = new HashSet<>(); // 응모자 아이디 사용 표시를 저장할 배열
		boolean[] visited = new boolean[8];
		Arrays.fill(visited, false);
		s = dfs(0, visited, s, user_id, banned_id);
		answer = s.size(); // 문자열 조합의 개수를 저장합니다.
		return answer;
	}
}

