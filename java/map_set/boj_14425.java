package map_set;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class boj_14425 {
	
	static HashMap<String, Integer> map;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] temp = br.readLine().split(" ");
		int N = Integer.parseInt(temp[0]);
		int M = Integer.parseInt(temp[1]);
		map = new HashMap<>();
		for (int i = 0 ; i < N; i++)
			map.put(br.readLine(), 1);
		int res = 0;
		for (int i = 0 ; i < M; i++)
			if (map.containsKey(br.readLine()))
				res++;
		System.out.println(res);
	}
}
