package epper;

import java.util.Scanner;

public class epper_상_2 {


	public static long solution(int n, int[] finalArray) {
		// bubble sort를 이용하여 순차적으로 정렬을 맞춰내려 간다
		long bridge = 0; // swap이 필요할때마다 bridge 값을 증가시킨다
		for (int i = 0; i < n; i++)
			for (int j = i - 1; j >= 0; j--)
				if (finalArray[j] > finalArray[i])
					bridge += 1;
		return bridge;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] finalArray = new int[n];
		for (int i = 0; i < n; i++) {
			finalArray[i] = scanner.nextInt();
		}
		System.out.println(solution(n, finalArray));
	}
}
