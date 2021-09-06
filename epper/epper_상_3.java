package epper;

import java.io.*;
import java.util.StringTokenizer;

class epper_상_3 {
	static int N;
	static int[] col = new int[15];
	static int[][] xy = new int[15][15];
	static int ans;

	public static int solution(int n, int k, int[] X, int[] Y) {
		N = n;
		for (int i = 0; i < k; i++)
			xy[X[i] - 1][Y[i]] = 1;
		queens(0);
		return ans;
	}

	private static void queens(int i) {
		if (promising(i)) {
			if (i == N) {
				ans++;
			} else {
				for (int j = 1; j <= N; j++) {
					if (xy[i][j] == 1) continue;
					col[i + 1] = j;
					queens(i + 1);
				}
			}
		}
	}

	private static boolean promising(int i) {
		int k = 1;
		boolean flag = true;
		while (k < i && flag) {
			if (col[i] == col[k] || Math.abs(col[i] - col[k]) == i - k) {
				flag = false;
			}
			k++;
		}
		return flag;
	}


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt((br.readLine()));
		int k = Integer.parseInt(br.readLine());

		st = new StringTokenizer(br.readLine());
		int[] X = new int[k];
		for (int i = 0; i < k; i++) {
			X[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		int[] Y = new int[k];
		for (int i = 0; i < k; i++) {
			Y[i] = Integer.parseInt(st.nextToken());
		}
		System.out.println(solution(n, k, X, Y));
	}
}