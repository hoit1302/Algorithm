package greedy;

import java.io.*;

public class boj_2847 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()); // 레벨 수
        int[] grades = new int[N]; // 레벨 점수
        for (int i = 0 ; i<N;i++)
            grades[i] = Integer.parseInt(br.readLine());

        // 알고리즘
        int res = 0;
        int tempMax = grades[N-1];
        for (int i = N-2 ; i >= 0; i--){
            if (tempMax <= grades[i]){
                int minus = grades[i] - tempMax + 1;
                res += minus;
                grades[i] -= minus;
            }
            tempMax = grades[i];
        }
        System.out.println(res);
    }
}
