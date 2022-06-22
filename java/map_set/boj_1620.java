package map_set;

import java.io.*;
import java.util.HashMap;

public class boj_1620 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] temp = br.readLine().split(" ");
		int N = Integer.parseInt(temp[0]);
		int M = Integer.parseInt(temp[1]);
		// 자료구조 2개 생성 (map -> 문자열로 바로 접근, arr-> index 번호로 바로 접근)
		HashMap<String, Integer> map = new HashMap<>();
		String[] arr = new String[N+1];
		for (int i = 1; i <= N; i++) {
			String word=br.readLine();
			map.put(word, i);
			arr[i] = word;
		}
		for (int i = 0; i < M; i++) {
			String word = br.readLine();
			if (Character.isDigit(word.charAt(0))) { // 숫자이면
				System.out.println(arr[Integer.parseInt(word)]);
			} else { // 문자이면
				System.out.println(map.get(word));
			}
		}
	}
	
}
