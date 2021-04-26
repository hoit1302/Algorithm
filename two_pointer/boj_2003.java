package two_pointer;

import java.io.*;
import java.util.StringTokenizer;

public class boj_2003 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		long[] arr = new long[N];
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		int a = 0, b = 0, tempSum = 0, answer = 0;
		while (true){
			if (M <= tempSum) tempSum -= arr[a++];
			else if (b == N) break;
			else tempSum += arr[b++];
			if (M == tempSum) answer++;
		}
		bw.write(answer + "\n");
		bw.flush();
	}
}
