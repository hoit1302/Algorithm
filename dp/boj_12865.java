package dp;

import java.util.*;
import java.lang.*;
import java.io.*;

class boj_12865 {
	static int[][] dp; // dp [i번 째 아이템][무게를 담을 수 있음]

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		dp = new int[N + 1][K + 1];

		ArrayList<Item> items = new ArrayList<>();
		items.add(new Item(0,0));
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			items.add(new Item(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}

		for(int i = 1; i <= N; i++){
			Item item = items.get(i);
			for(int j = 1; j <= K; j++){
				dp[i][j] = dp[i - 1][j];
				if(j - item.W >= 0){
					dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - item.W] + item.V);
				}
			}
		}
		bw.write(dp[N][K] + "\n");
		bw.flush();
	}

	static class Item {
		int W, V;
		public Item(int W, int V) {
			this.W = W;
			this.V = V;
		}
	}
}