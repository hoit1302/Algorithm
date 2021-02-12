package dijkstra;

import java.io.*;
import java.util.*;

public class boj_1916 {
	private static final long INF = (long) 1e18;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int V = Integer.parseInt(br.readLine());
		int E = Integer.parseInt(br.readLine());
		ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
		for (int i = 0; i <= V; i++) graph.add(new ArrayList<>()); // V(정점개수)번 추가하기
		for (int i = 0; i < E; i++) {// E(간선개수)번 입력받기
			st = new StringTokenizer(br.readLine());
			graph.get(Integer.parseInt(st.nextToken()))
				.add(new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());

		PriorityQueue<PQ> pq = new PriorityQueue<>(
			Comparator.comparing(o -> o.accumulatedDist) // 맨날 까먹음
		);
		long[] dist = new long[V + 1];
		Arrays.fill(dist, INF);
		dist[start] = 0;
		pq.add(new PQ(0, start));
		while (!pq.isEmpty()) {
			PQ now = pq.poll();
			if (dist[now.vertex] < now.accumulatedDist) continue;
			for (Edge next : graph.get(now.vertex)) {
				if (dist[now.vertex] + next.w < dist[next.v]) {
					dist[next.v] = dist[now.vertex] + next.w;
					pq.add(new PQ(dist[next.v], next.v));
				}
			}
		}

		bw.write(dist[end] + "\n");
		bw.flush();
	}

	private static class Edge {
		int v, w;

		public Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}

	private static class PQ {
		long accumulatedDist;
		int vertex;

		public PQ(long accumulatedDist, int vertex) {
			this.accumulatedDist = accumulatedDist;
			this.vertex = vertex;
		}
	}
}
