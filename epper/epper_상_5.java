package epper;

import java.io.*;
import java.util.*;

public class epper_상_5 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int[][] adj = new int[N + 1][];
		adj[0] = new int[]{0};
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			List<Integer> arrayList = new ArrayList<>();
			while (true) {
				int temp = Integer.parseInt(st.nextToken());
				arrayList.add(temp);
				if (temp == 0) {
					adj[i] = arrayList.stream().mapToInt(Integer::intValue).toArray();
					break;
				}
			}
		}

		int M = Integer.parseInt(br.readLine());
		int[] firstInfected = new int[M];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			int temp = Integer.parseInt(st.nextToken());
			firstInfected[i] = temp;
		}
		Arrays.stream(solution(N, adj, M, firstInfected)).forEach(t -> sb.append(t).append(" "));
		System.out.println(sb);
	}

	public static int[] solution(int N, int[][] adj, int M, int[] firstInfected) {
		Queue<Integer> Q = new ArrayDeque<>(); // 감염된 사람의 번호를 큐에 저장할 것이다.
		int[] answer = new int[N + 1]; // solution 함수에서 리턴할 배열
		Arrays.fill(answer, -1); // 사이즈 N+1, -1로 초기화
		int[] turn = new int[N + 1]; // 감염까지 남은 주변 비감염 사람 수
		Arrays.fill(turn, 0); // 사이즈 N+1, 0로 초기화

		// 최조생성자 처리
		for (int t : firstInfected) {
			Q.add(t); // 최조생성자는 감염된 사람이고 주변인에게 영향을 주므로 큐에 넣어주고
			answer[t] = 0; // 0분에 감염되었음을 저장한다.
		}

		// 주변인의 절반 이상이 루머를 믿을 때 본인도 루머를 믿으므로
		// 몇 명이 감염되었을 때 자신이 감염되는지에 대한 정보를
		// 사람 i의 주변인물 수 + 1 / 2의 몫으로 저장해둔다.
		// 사람의 번호가 아닌 입력의 끝을 말하는 0이 adj 배열에 포함되어 있으므로 + 1은 안해도 된다.
		for (int i = 1; i <= N; i++)
			turn[i] = adj[i].length / 2;

		while (!Q.isEmpty()) { // 큐가 빌 때까지 탐색하는데, 큐가 비었다면 모든 탐색을 마쳤다는 의미이다.
			int current = Q.poll(); // 현재, 가장 먼저 감염된 사람의

			for (Integer next : adj[current]) { // 주변인물들에게
				if (next == 0) break;
				turn[next] -= 1; // 자신(주변인물)이 감염되기까지 남은 사람 수를 1 빼고
				if (answer[next] == -1 && turn[next] <= 0) { // 만약 아직 감염되지 않았고 주변인의 반 이상이 감염되었다면
					Q.add(next); // 감염되었기에 큐에 자신의 번호를 넣어주고
					answer[next] = answer[current] + 1; // 자신을 감염시킨 마지막 주변인의 감염된 시간 + 1분을 더해 저장한다.
				}
			}
		}

		// 계산의 편의를 위해 배열에 0번 index가 아닌 1번 index부터 정답이 저장되었으므로,
		// 배열을 두번째 원소부터 잘라 반환한다.
		return Arrays.copyOfRange(answer, 1, answer.length);
	}
}

