package bellmanford;

import java.io.*;
import java.util.*;

public class boj_1865 {

	static class Edge {
		int v, w;

		Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}

	static int[] dist;
	static final int INF = (int) 1e9;
	static ArrayList<ArrayList<Edge>> Graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int W = Integer.parseInt(st.nextToken());

			Graph = new ArrayList<>();
			for (int i = 0; i <= N; i++) Graph.add(new ArrayList<>());
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int u = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				int w = Integer.parseInt(st.nextToken());
				Graph.get(u).add(new Edge(v, w));
				Graph.get(v).add(new Edge(u, w));
			}
			for (int i = 0; i < W; i++) {
				st = new StringTokenizer(br.readLine());
				int u = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				int w = Integer.parseInt(st.nextToken());
				Graph.get(u).add(new Edge(v, -w));
			}

			dist = new int[N + 1];
			Arrays.fill(dist, INF);
			dist[1] = 0;

			boolean updated = false;
			for (int i = 1; i <= N; i++) {
				updated = false;
				for (int from = 1; from <= N; from++) {
					for (int a = 0; a < Graph.get(from).size(); a++) {
						int to = Graph.get(from).get(a).v;
						int cost = Graph.get(from).get(a).w;
						if (dist[to] > dist[from] + cost) {
							dist[to] = dist[from] + cost;
							updated = true;
						}
					}
				}
				if (!updated) {
					bw.write("NO\n");
					break;
				}
			}
			if (updated) bw.write("YES\n");
		}
		bw.flush();
	}
}
