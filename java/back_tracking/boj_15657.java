package back_tracking;

import java.io.*;
import java.util.*;

public class boj_15657 {

    static StringBuilder sb;
    static Stack<Integer> stack;
    static int[] nums;
    static int N, M;
    static boolean[] visited;

    private static void func(int order, int startIndex) {
        if (order == M + 1) {
            stack.forEach((num) -> sb.append(num).append(" "));
            sb.append("\n");
            return;
        }
        for (int index = startIndex; index < N; index++) {
            if (!visited[index]) {
                stack.push(nums[index]);
                func(order + 1, index);
                stack.pop();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        sb = new StringBuilder();
        stack = new Stack<>();
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new boolean[N]; // 모두 false
        nums = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(nums);
        func(1, 0);
        bw.write(sb.toString());
        bw.flush();
    }
}
