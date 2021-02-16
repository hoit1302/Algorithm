package bellmanford;

import java.io.*;
import java.util.*;

public class boj_11657 {

	static class Edge {
		int v, w;

		Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}

	static long[] dist;
	static final long INF = (int) 1e18;
	static ArrayList<ArrayList<Edge>> Graph;


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		Graph = new ArrayList<>();
		int V = Integer.parseInt(st.nextToken());
		long E = Integer.parseInt(st.nextToken());

		for (int i = 0; i <= V; i++) Graph.add(new ArrayList<>());
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			Graph.get(u).add(new Edge(v, w));
		}
		dist = new long[V + 1];
		Arrays.fill(dist, INF);
		dist[1] = 0;

		boolean isNegativeCycle = false;
		for (int i = 1; i <= V; i++) {
			for (int from = 1; from <= V; from++) {
				if (dist[from] == INF) continue; // 이어지지 않은 정점은 패스
				for (int a = 0; a < Graph.get(from).size(); a++) {
					int to = Graph.get(from).get(a).v;
					int cost = Graph.get(from).get(a).w;
					if (dist[to] > dist[from] + (long)cost) {
						if (i == V) isNegativeCycle = true;
						dist[to] = dist[from] + (long)cost;
					}
				}
			}
		}

		if (isNegativeCycle) bw.write("-1\n");
		else {
			for (int i = 2; i <= V; i++) {
				if (dist[i] == INF) bw.write("-1\n");
				else bw.write(dist[i] + "\n");
			}
		}
		bw.flush();
	}
}
