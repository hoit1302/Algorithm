package back_tracking;

import java.io.*;
import java.util.*;

public class boj_15651 {
    static int N, M;
    static Stack<Integer> stack;
    static StringBuilder sb;
    private static void func(int order) throws IOException {
        if (order == M + 1) {
            stack.forEach((num) -> sb.append(num).append(" ")); sb.append("\n");
            return;
        }
        for (int i = 1; i <= N; i++) {
            stack.push(i);
            func(order + 1);
            stack.pop();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        sb = new StringBuilder("");
        stack = new Stack<>();
        func(1);
        bw.write(String.format("%s", sb));
        bw.flush();
    }
}
