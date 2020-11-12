package tree;
// 완전 이진 트리
// 입력은 중순위 운행
// 출력은 레벨 순위 운행

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj_9934 {
	static int nodenum, K;
	static int[] arr;
	static List<Integer>[] res;

	static void go(int start, int depth) {
		res[depth].add(arr[start]);
		// System.out.println(depth + "층, " + arr[start]);
		if (depth + 1 <= K) {
			int down = start - ((int) Math.pow(2.0, (K - 1) - depth));
			if (0 <= down && down < nodenum)
				go(down, depth + 1);
			int up = start + ((int) Math.pow(2.0, (K - 1) - depth));
			if (0 <= up && up < nodenum)
				go(up, depth + 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K = Integer.parseInt(br.readLine());
		String[] temp = br.readLine().split(" ");
		nodenum = (int) Math.pow(2.0, (double) K) - 1;
		arr = new int[nodenum];
		for (int i = 0; i < nodenum; i++)
			arr[i] = Integer.parseInt(temp[i]);

		res = new ArrayList[K + 1];
		for (int i = 1; i <= K; i++)
			res[i] = new ArrayList<Integer>();
		go(nodenum / 2, 1);

		for (int i = 1; i <= K; i++) {
			Iterator<Integer> it = res[i].iterator();
			while (it.hasNext())
				System.out.print(it.next() + " ");
			System.out.println();
		}
	}
}
