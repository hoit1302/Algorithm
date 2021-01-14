package back_tracking;

import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class boj_15652 {
    static int N, M;
    static Stack<Integer> stack;
    static StringBuilder sb;

    private static void func(int order, int num) {
        if (order == M+1) {
            stack.forEach((n) -> sb.append(n).append(" "));
            sb.append("\n");
            return;
        }
        for (int i = num; i <= N; i++){
            stack.push(i);
            func(order+1, i);
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
        func(1, 1);
        bw.write(String.format("%s", sb));
        bw.flush();
    }
}
