package greedy;

import java.util.Scanner;

public class epper_15_7 {
	//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
	public static int solution(int[] s, int[] e, int N) {

		// 종료 시간을 기준으로 오름차순 정렬
		for (int i = N - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				// 종료 시간이 같은 경우 시작 시간을 오름차순으로 정렬
				if ((e[j] > e[j + 1]) || (e[j] == e[j + 1]) && (s[j] > s[j + 1])) {
					// 버블 정렬 (인접한 두 요소끼리 바꿈)
					int tmp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = tmp;
					tmp = e[j];
					e[j] = e[j + 1];
					e[j + 1] = tmp;
				}
			}
		}

		// e1, e2 두 포인트가 존재하는데 끝나는 시간이 시작 시간보다 빠르거나 같은 게 있으면 갱신.
		// e1의 값을 e2에 저장하면서 e1이 늦게 끝나는 좌석으로 유지시킴
		int answer = 0, e1 = -1, e2 = -1;
		for (int i = 0; i < N; i++) {
			if (e1 <= s[i]) {
				answer++;
				e1 = e[i];
			} else if (e2 <= s[i]) {
				e2 = e1;
				e1 = e[i];
				answer++;
			}
		}

		return answer;
	}

	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(System.in);
		int[] s = new int[1000];
		int[] e = new int[1000];
		int N;
		N = scan.nextInt();
		for (int i = 0; i < N; i++)
			s[i] = scan.nextInt();
		for (int i = 0; i < N; i++)
			e[i] = scan.nextInt();
		System.out.print(solution(s, e, N));
	}
}
