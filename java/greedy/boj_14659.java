package greedy;

import java.io.*;
import java.util.*;

public class boj_14659 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] mountains = new int[N];
        int i = 0;
        while (st.hasMoreTokens())
            mountains[i++] = Integer.parseInt(st.nextToken());

        int tmp = 0, res = 0, tempMountain = mountains[0];
        for (i = 1; i < N; i++){
            if (tempMountain < mountains[i]) {// 더이상 죽일 수 없음.
                tempMountain = mountains[i];
                res = Math.max(res, tmp);
                tmp = 0;
            } else { // 죽일 수 있음
                tmp++;
                res = Math.max(res, tmp);
            }

        }
        System.out.println(res);
    }

}
