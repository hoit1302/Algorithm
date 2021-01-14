package back_tracking;

import java.io.*;
import java.util.*;

public class boj_15649 {
    static int N, M;
    static Stack<Integer> arr;
    static boolean[] visited;
    public static void func(int order){
        if (order == M+1){
            arr.forEach((n) -> System.out.print(n + " "));
            System.out.println();
            return;
        }
        for (int i = 1; i <= N; i++){
            if (!visited[i]) {
                arr.push(i); visited[i]=true;
                func(order+1);
                arr.pop(); visited[i]=false;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); M = sc.nextInt();
        visited = new boolean[N+1]; // 방문하지 않았음으로 초기화되어 있음.
        arr = new Stack<>();
        func(1);
    }
}
