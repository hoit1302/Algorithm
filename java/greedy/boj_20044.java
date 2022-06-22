package greedy;

import java.io.*;
import java.util.*;

public class boj_20044 {
    public static void main(String[] args) throws IOException {
        // 입력받기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()); // 팀 수
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] grades = new int[2*N];
        for (int i = 0 ; i < 2*N; i++)
            grades[i] = Integer.parseInt(st.nextToken());

        // 평범하게 오름차순으로 정렬
        Arrays.sort(grades);

        // 알고리즘
        int min = grades[0] + grades[2*N-1], tmp = 0;
        for (int i = 1 ; i < N; i++){
            tmp = grades[i] + grades[2*N-i-1];
            min = Math.min(tmp, min);
        }
        System.out.println(min);
    }
}
