package back_tracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_9663 {
    private static int N, res;
    private static boolean[] isUsed1, isUsed2, isUsed3;
    private static void func(int order) {
        if (order == N){
            res++;
            return;
        }
        for (int i = 0; i < N; i++){
            if (isUsed1[i] || isUsed2[i + order] || isUsed3[order - i + N - 1]) continue;
            isUsed1[i] = true;
            isUsed2[i + order] = true;
            isUsed3[order - i + N - 1] = true;
            func(order + 1);
            isUsed1[i] = false;
            isUsed2[i + order] = false;
            isUsed3[order - i + N - 1] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        isUsed1 = new boolean[N];
        isUsed2 = new boolean[2 * N];
        isUsed3 = new boolean[2 * N];
        func(0);
        System.out.println(res);
    }
}
