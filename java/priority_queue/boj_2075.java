package priority_queue;

import java.io.*;
import java.util.*;

//우선순위 변경하기
//Java는 기본적으로 낮은 숫자부터 큰 숫자까지 오름차순으로 정렬
//만약 다른 오름차순으로 정렬하고 싶다면 Comparator 클래스나 Comparable 인터페이스를 이용해야 함.

public class boj_2075 {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		int N = Integer.parseInt(br.readLine());
		for (int i = 0 ; i < N; i++) {
			String[] temp = br.readLine().split(" ");
			for (String str : temp)
				pq.add(Integer.parseInt(str));
		}
		int res = 0;
		for (int i = 0; i < N; i++)
			res = pq.poll();
		
		System.out.println(res);
	}
}
