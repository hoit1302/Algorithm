package dfs_bfs;

import java.io.*;
import java.util.*;

public class boj_1260 {
	private static ArrayList<ArrayList<Integer>> adjacencyList;
	private static boolean[] isCheck;
	private static StringBuilder sb;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int V = Integer.parseInt(st.nextToken());

		adjacencyList = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i <= N; i++) adjacencyList.add(new ArrayList<Integer>());
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			adjacencyList.get(a).add(b);
			adjacencyList.get(b).add(a);
		}
		for (int i = 1; i <= N; i++) Collections.sort(adjacencyList.get(i));

		isCheck = new boolean[N + 1];
		dfs(V);
		sb.append("\n");

		isCheck = new boolean[N + 1];
		bfs(V);
		sb.append("\n");

		bw.write(String.valueOf(sb));
		bw.flush();
	}

	static void dfs(int V) {
		if (isCheck[V]) return;

		isCheck[V] = true;
		sb.append(V).append(" ");
		for (int temp : adjacencyList.get(V)) {
			dfs(temp);
		}
	}

	static void bfs(int v) {
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(v);
		isCheck[v] = true;
		sb.append(v).append(" ");

		while(!queue.isEmpty()) {
			int x = queue.poll();
			for (int temp : adjacencyList.get(x)) {
				if (!isCheck[temp]) {
					isCheck[temp] = true;
					queue.add(temp);
					sb.append(temp).append(" ");
				}
			}
		}
	}

}

