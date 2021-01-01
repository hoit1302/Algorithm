package Implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_16961 {
	static int ans1, ans2, ans3, ans4, ans5;
	static int[][] days = new int[2][367]; // T: days[0], S: days[1]

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine()); // 사람 수, 최대 5000명

		while (N-- > 0) {
			String[] temp = br.readLine().split(" ");
			String c = temp[0];
			int start = Integer.parseInt(temp[1]);
			int end = Integer.parseInt(temp[2]);
			if (c.equals("T"))
				for (int i = start; i <= end; i++)
					days[0][i]++;
			else
				for (int i = start; i <= end; i++)
					days[1][i]++;
			ans5 = Math.max(ans5, end - start + 1);
		}

		for (int i = 1; i <= 366; i++) {
			if (days[0][i] > 0 || days[1][i] > 0) {
				ans1++;
				ans2 = Math.max(ans2, days[0][i] + days[1][i]);
				if (days[0][i] > 0 && days[1][i] > 0 && days[0][i] == days[1][i]) {
					ans3++;
					ans4 = Math.max(ans4, days[0][i] + days[1][i]);
				}
			}

		}

		System.out.printf("%d\n%d\n%d\n%d\n%d\n", ans1, ans2, ans3, ans4, ans5);
	}

}
