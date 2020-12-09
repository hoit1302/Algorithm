package dfs_bfs;

import java.io.*;
import java.util.*;

public class boj_2644 {
	static int n;
	static int st, ed;
	static int answer = -1;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		Node[] nodes = new Node[n];
		for (int i = 0; i < n; i++)
			nodes[i] = new Node();

		String[] temp = br.readLine().split(" ");
		st = Integer.parseInt(temp[0]) - 1;
		ed = Integer.parseInt(temp[1]) - 1;
		nodes[ed].isDest = true;

		// 간선 연결
		int lineNum = Integer.parseInt(br.readLine());
		for (int i = 0; i < lineNum; i++) {
			temp = br.readLine().split(" ");
			int a = Integer.parseInt(temp[0]) - 1;
			int b = Integer.parseInt(temp[1]) - 1;
			nodes[a].con.add(nodes[b]);
			nodes[b].con.add(nodes[a]);
		}
		
		// 탐색, dfs
		nodes[st].visited = true;
		dfs(nodes[st], 0);

		System.out.printf("%d\n", answer);

	}

	private static void dfs(Node node, int sum) {
		if (node.isDest == true) {
			answer = sum;
			return;
		} else {
			for (Node nd : node.con) {
				if (nd.visited == false) {
					nd.visited = true;
					dfs(nd, sum + 1);
					nd.visited = false;
				}
			}
		}
	}

	private static class Node {
		boolean visited = false;
		boolean isDest = false;
		List<Node> con = new ArrayList<>();
	}
}
