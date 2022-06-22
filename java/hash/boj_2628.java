package hash;

import java.io.*;
import java.util.*;
// 가로와 세로 변수를 반대로 설정함. 왜 해싱 문제인지는 아직 잘 모르겠음.
public class boj_2628 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] temp = br.readLine().split(" ");
		int H = Integer.parseInt(temp[0]); // 가로길이
		int W = Integer.parseInt(temp[1]); // 세로길이
		int N = Integer.parseInt(br.readLine());
		ArrayList<Integer> Ws = new ArrayList<>();
		Ws.add(0);
		Ws.add(W);
		ArrayList<Integer> Hs = new ArrayList<>();
		Hs.add(0);
		Hs.add(H);
		int w_num = 2, h_num = 2;
		for (int i = 0; i < N; i++) {
			temp = br.readLine().split(" ");
			int n1 = Integer.parseInt(temp[0]);
			int n2 = Integer.parseInt(temp[1]);
			if (n1 == 0) { // 가로 선이 생김
				Ws.add(n2);
				w_num++;
			} else {// 세로 선이 생김
				Hs.add(n2);
				h_num++;
			}
		}
		Collections.sort(Ws);
		Collections.sort(Hs);
		int MaxW = 0, MaxH = 0;
		for (int i = 0; i < w_num - 1; i++)
			if (Ws.get(i + 1) - Ws.get(i) > MaxW)
				MaxW = Ws.get(i + 1) - Ws.get(i);
		for (int i = 0; i < h_num - 1; i++)
			if (Hs.get(i + 1) - Hs.get(i) > MaxH)
				MaxH = Hs.get(i + 1) - Hs.get(i);
		System.out.println(MaxW * MaxH);
	}
}
