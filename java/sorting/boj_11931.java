package sorting;

import java.io.*;
import java.util.*;

public class boj_11931 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(br.readLine());

		arr = Arrays.stream(arr).boxed().sorted(Collections.reverseOrder())
			.mapToInt(Integer::intValue).toArray();

		for (int i = 0; i < N; i++) bw.write(arr[i] + "\n");
		bw.flush();
	}
}
