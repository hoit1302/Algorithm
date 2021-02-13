package dijkstra;

import java.io.*;
import java.util.*;

public class boj_1753 {
	// 간선 개수 * 간선의 가중치 최대 값
	private static final long INF = (long) 1e18;

	// 보통 (u, v, w)로 (시작, 끝, 가중치)을 나타낸대.
	static class Edge {
		int v, w;

		Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}
	// vertex 까지 누적된 거리합이 accumulatedDist 인 경우가 있어.
	static class PQ {
		long accumulatedDist;
		int vertex;

		PQ(long accumulatedDist, int vertex) {
			this.accumulatedDist = accumulatedDist;
			this.vertex = vertex;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(br.readLine()); // 시작점이 주어졌어.
		ArrayList<ArrayList<Edge>> v = new ArrayList<>();
		for (int i = 0; i <= V; i++) v.add(new ArrayList<>());
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			v.get(Integer.parseInt(st.nextToken()))
				.add(new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		long[] dist = new long[V + 1 + 1];
		Arrays.fill(dist, INF);
		dist[K] = 0;
		// 𝑝𝑞: (현재 정점까지 누적된 거리, 현재 정점 번호)
		PriorityQueue<PQ> pq =
			new PriorityQueue<>(
				Comparator.comparingLong(o -> o.accumulatedDist) // pq의 정렬 기준을 꼭 입력하기!
			);
		pq.add(new PQ(0, K));

		while (!pq.isEmpty()) {
			PQ now = pq.poll();
			// 다음 정점들을 현재 선택된 값으로 계산하기 전에, 현재 정점에 대해 이미 더 작은 값이 들어있다면 갱신할 필요없음!!!
			if (dist[now.vertex] < now.accumulatedDist) continue; // 여기가 제일 어렵다
			for (Edge next : v.get(now.vertex)) {
				if (now.accumulatedDist + next.w < dist[next.v]) {
					dist[next.v] = now.accumulatedDist + next.w;
					pq.add(new PQ(dist[next.v], next.v)); // vertex 까지 누적된 거리합이 accumulatedDist 인 경우가 있어.
				}
			}
		}

		// 출력
		for (int i = 1; i <= V; i++) {
			if (dist[i] == INF) sb.append("INF\n");
			else sb.append(dist[i]).append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
	}
}
