package greedy;

import java.io.*;
import java.util.*;

public class boj_16200 {
	static int ans;

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine()); // 사람 수
		ans = N;
		String[] nums = br.readLine().split(" ");
		ArrayList<Integer> list = new ArrayList<>();
		int i = 0;
		for (String strnum : nums)
			list.add(Integer.parseInt(strnum)); // 입력받음
		Collections.sort(list);
		Collections.reverse(list);
		int temp = 1;
		for (i = 0; i < N-1; i++) {
			int tempMax = list.get(i); // 현재 최대 묶일 수 있는 값
			if (tempMax == list.get(i+1)) {
				temp++;
				if (temp <= tempMax) {
					ans--;
				} else {
					temp = 1;
				}
			} else { // 앞의 숫자와 다름
				tempMax = list.get(i+1);
				temp++;
				if (temp <= tempMax) {
					ans--;
				} else {
					temp = 1;
				}
			}
		}
		System.out.println(ans);
	}

}
