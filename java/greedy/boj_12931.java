package greedy;

import java.io.*;
import java.util.*;

public class boj_12931 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        int res = 0, i = 0;

        while (st.hasMoreTokens())
            arr[i++] = Integer.parseInt(st.nextToken());

        // 알고리즘
        while (true) {
            boolean allZero = true, allDivTwo = true;
            // 모두 0이야?
            for (Integer num : arr) {
                if (num != 0) // 아니야!
                    allZero = false;
            } if (allZero) break; // 응! 결과 출력
            // 모두 2로 나눠져?
            for (Integer num : arr) {
                if (num % 2 != 0)
                    allDivTwo = false;
            }
            if (allDivTwo) { // 응
                res++;
                for (i = 0; i < N; i++)
                    arr[i] /= 2;
            } else { // 아냐
                for (i = 0; i < N; i++)
                    if (arr[i]%2!=0) {
                        res++;
                        arr[i]--;
                    }
            }
        }
        System.out.println(res);
    }
}